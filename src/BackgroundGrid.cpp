#include "BackgroundGrid.h"


#include "ResourceManager.h"
#include "Screen.h"
#include "Vector2.h"
#include <vector>
#include <iostream>
#include <string>

#include <cstdlib>

BackgroundGrid* BackgroundGrid:: _BG_instance = 0;

BackgroundGrid* BackgroundGrid::Instance(){
    if(!_BG_instance)
    {
        _BG_instance = new BackgroundGrid;
    }
    return _BG_instance;
}


BackgroundGrid::BackgroundGrid():_position (0, 0){
_grid.resize(24);

for( int i = 0; i < 23; i ++ )
{
    //c++11 assign
    _grid[i] = {9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9};
}

_grid[23] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};

//show_grid();
_pileTop = 23;
_image =(Image*) ResourceManager::Instance()->GetResource("grid.png");
_position = Vector2(0,Screen::GetHeight ())+ Vector2( Screen::GetWidth() / 2 - _image->GetWidth() / 2, 0 );

}

BackgroundGrid::~BackgroundGrid(){

}

void BackgroundGrid::show_grid(){
for( int i = 0; i < 24; i ++ )
{
    for( int j = 0; j < 12; j ++ )
    {
        std::cout<<_grid[i][j]<<" ";
    }
    std::cout<<"\n";
}
std::cout<<"\n";
std::cout<<"pile top:"<<_pileTop<<"\n";

}

unsigned int BackgroundGrid::MinHeight(Tetromino * tet){

unsigned int minHeight = 1;


bool flag = true;
while( flag )
{
if( OverLap( tet->GetShape(), tet->GetV() + minHeight, tet->GetH() ) )
    break;
minHeight++;
}
return minHeight;

}

bool BackgroundGrid::FullLine( unsigned int v ){
for( int i = 0; i < 10; i ++ )
{
    if ( _grid[v][i+1] == 0 )
        return false;
}
return true;
}

bool BackgroundGrid::EmptyLine( unsigned int v ){
for( int i = 0; i < 10; i ++ )
{
    if ( _grid[v][i+1] != 0 )
        return false;
}
return true;
}

void BackgroundGrid::Lower( unsigned int v ){
for( unsigned int i = v; i >= _pileTop; i -- )
    for( unsigned int j = 0; j < 10; j++)
    {
        _grid[i][1+j] = _grid[i-1][1+j];
    }

_pileTop--;
}

void BackgroundGrid::LineClear(unsigned int v){
for( int i = 0; i < 10; i ++ )
{
   _grid[v][i+1] = 0;
}
}

void BackgroundGrid::Settle(){
//std::cout<<"settling...\n";
unsigned int i = _pileTop;
while( i < 23 && EmptyLine(i) )
{
    i++;
}
_pileTop = i;
while( i < 23 )
{
    if( FullLine(i) )
    {
        LineClear(i);
        Lower(i);
        //counter++;
        i = _pileTop;
    }
    else
        i++;
}
}

void BackgroundGrid::Draw(){


Screen::Draw( _image,_position );

for( unsigned int i = 23; i >= _pileTop; i-- )
{
    for( unsigned int j = 0; j <10; j++ )
    {
        if( _grid[i][1+j] > 0 && _grid[i][1+j] < 9 )
            {char x = _grid[i][1+j] + 48;
            std::string lb;
            lb += "color";
            lb += x;
            lb += ".png";
            Screen::Draw( (Image*)ResourceManager::Instance()->GetResource(lb) , Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2( j * 31, -(int)(i * 31)) );
            }
    }
}
}

void BackgroundGrid::Update(){

}

Vector2 BackgroundGrid::GetPosition(){
return _position;
}

bool BackgroundGrid::RoomLeft(Tetromino * tet){

if(OverLap(tet->GetShape(), tet->GetV(), tet->GetH()-1))
    return false;
return true;
}

bool BackgroundGrid::RoomRight(Tetromino * tet){

if(OverLap(tet->GetShape(), tet->GetV(), tet->GetH()+1))
    return false;
return true;
}

bool BackgroundGrid::RoomDown( Tetromino * tet ){

if(OverLap(tet->GetShape(), tet->GetV()+1, tet->GetH()))
    return false;
return true;
}

void BackgroundGrid::SetPiece(Tetromino * tet){
unsigned int v,h;
std::vector< std::vector <int> > tempShape;

    v = tet->GetV();
    h = tet->GetH();
    tempShape = tet->GetShape();


for( unsigned int i = 0; i < tempShape.size(); i ++ )
    {
        for( unsigned int j = 0; j < tempShape[i].size(); j ++ )
        {
         if( tempShape[i][j] != 0 )
            _grid[v+i][1+h+j] = tempShape[i][j];
        }
    }
if(v<_pileTop)
    _pileTop = v;
}

bool BackgroundGrid::OverLap( std::vector< std::vector <int> >  tempShape, unsigned int v, unsigned int h ){

for( unsigned int i = 0; i < tempShape.size(); i ++ )
    {
        for( unsigned int j = 0; j < tempShape[i].size(); j ++ )
        {
            if( _grid[ v + i ][ 1 + h + j ] != 0 && tempShape[i][j] != 0 )
                return true;
        }
    }

return false;

}

bool BackgroundGrid::ReachedTop(){
if(_pileTop <= 3)
    return true;
return false;
}
