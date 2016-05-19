#include "BackgroundGrid.h"
#include "TestDot.h"

#include "Resources.h"

#include "Screen.h"
#include "Input.h"
#include "Vector2.h"
#include <vector>
#include <iostream>

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
_image = Resources::LoadImage ("Assets/Images/grid_2.png");
_position = Vector2(0,Screen::GetHeight ())+ Vector2( Screen::GetWidth() / 2 - _image->GetWidth() / 2, -20 );
_colors[0] = Resources::LoadImage ("Assets/Images/badris/1.png");
}

BackgroundGrid::~BackgroundGrid(){
delete _image;
for(int i = 0; i < 7; i ++ )
    delete _colors[i];

}

unsigned int BackgroundGrid::GetPileTop(){
return _pileTop;
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

}

unsigned int BackgroundGrid::MinHeight(Tetronimo * tet){

unsigned int v,h;
unsigned int LowestPointV = tet->GetHeight() - 1;
std::vector<int> LowestPointsH;

v = tet->GetV();
h = tet->GetH();
LowestPointsH = tet->GetDownSide();

unsigned int minHeight = 1;

bool flag = true;
while( flag )
{for( unsigned int k = 0; k < LowestPointsH.size(); k ++ )
    {
        if(_grid[ v + LowestPointV + minHeight ][ 1 + h + LowestPointsH[k] ] != 0)
            {flag = false;
            break;
            }
    }
if( flag == true )
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
        if( _grid[i][1+j] != 0 && _grid[i][1+j] != 9 )
            {
            Screen::Draw( _colors[ _grid[i][1+j]-1 ] , Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2( 4+j * 23, -(int)(4+i * 22)) );
            }
    }
}
}

void BackgroundGrid::Update(){

}

Vector2 BackgroundGrid::GetPosition(){
return _position;
}

bool BackgroundGrid::RoomLeft(Tetronimo * tet){

unsigned int v,h;
unsigned int leftmostPointH = 0;
std::vector< int > leftmostPointsV = tet -> GetLeftSide();
v = tet->GetV();
h = tet->GetH();

for( unsigned int k = 0; k < leftmostPointsV.size(); k ++ )
    {if( _grid[ v + leftmostPointsV[k] ][ 1 + h + leftmostPointH - 1 ] != 0 )
        return false;
    }
return true;

}

bool BackgroundGrid::RoomRight(Tetronimo * tet){

unsigned int v,h;
unsigned int rightmostPointH = tet->GetWidth()-1;
std::vector< int > rightmostPointsV = tet -> GetRightSide();
v = tet->GetV();
h = tet->GetH();

for( unsigned int k = 0; k < rightmostPointsV.size(); k ++ )
    {if( _grid[ v + rightmostPointsV[k] ][ 1 + h + rightmostPointH + 1 ] != 0 )
        return false;
    }
return true;

}

bool BackgroundGrid::RoomDown( Tetronimo * tet ){

unsigned int v,h;
unsigned int lowestPointV = tet->GetHeight()-1;
std::vector<int> lowestPointsH;

v = tet->GetV();
h = tet->GetH();
lowestPointsH = tet->GetDownSide();

for( unsigned int k = 0; k < lowestPointsH.size(); k ++ )
    {
        if(_grid[ v + lowestPointV + 1 ][ 1 + h + lowestPointsH[k] ] != 0)
            return false;
    }

return true;

}

void BackgroundGrid::SetPiece(Tetronimo * tet){
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
//std::cout<<_pileTop;
}

bool BackgroundGrid::OverLap(Tetronimo * tet){

unsigned int v,h;
std::vector< std::vector <int> > tempShape;
    v = tet->GetV();
    h = tet->GetH();
    tempShape = tet->GetShape();

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

//!de aici trb modif
bool BackgroundGrid::RoomLeftInside(Tetronimo * tet){

unsigned int v,h;
unsigned int leftmostPointH = tet->GetWidth() - 1 ;
std::vector< int > leftmostPointsV = tet -> GetRightSide();
v = tet->GetV();
h = tet->GetH();

for( unsigned int k = 0; k < leftmostPointsV.size(); k ++ )
    {if( _grid[ v + leftmostPointsV[k] ][ 1 + h + leftmostPointH - 1 ] != 0 )
        return false;
    }
return true;

}

bool BackgroundGrid::RoomRightInside(Tetronimo * tet){

unsigned int v,h;
unsigned int rightmostPointH = 0;
std::vector< int > rightmostPointsV = tet -> GetLeftSide();
v = tet->GetV();
h = tet->GetH();

for( unsigned int k = 0; k < rightmostPointsV.size(); k ++ )
    {if( _grid[ v + rightmostPointsV[k] ][ 1 + h + rightmostPointH + 1 ] != 0 )
        return false;
    }
return true;

}

bool BackgroundGrid::RoomDownInside( Tetronimo * tet ){

unsigned int v,h;
unsigned int lowestPointV = 0;
std::vector<int> lowestPointsH;

v = tet->GetV();
h = tet->GetH();
lowestPointsH = tet->GetTopSide();

for( unsigned int k = 0; k < lowestPointsH.size(); k ++ )
    {
        if(_grid[ v + lowestPointV + 1 ][ 1 + h + lowestPointsH[k] ] != 0)
            return false;
    }

return true;

}

