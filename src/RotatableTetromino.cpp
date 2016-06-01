#include "RotatableTetromino.h"

#include "BackgroundGrid.h"
#include "Screen.h"
#include "Input.h"
#include "GameTime.h"
#include "Vector2.h"
#include "ResourceManager.h"

#include <cstdlib>
#include <iostream>

#define INIT_POS_H 4
#define INIT_POS_V 0

RotatableTetromino::RotatableTetromino()
{

}

RotatableTetromino::~RotatableTetromino(){
}

void RotatableTetromino::Draw(){
DrawShadow();
Screen::Draw( _image[_rotation],_position );

}

void RotatableTetromino::Update(){

if(BackgroundGrid::Instance()->ReachedTop())
{
    return;
}

unsigned int _turn = BackgroundGrid::Instance()->GetTurn();
Vector2 SideMovement = Vector2::Zero;
Vector2 DownMovement = Vector2::Zero;
int hMovement = 0, vMovement = 0;

if(Input::GetKeyDown('a'))
{
    if(BackgroundGrid::Instance()->RoomLeft(this))
        {SideMovement = Vector2( -31, 0 );
        hMovement = -1;
        }
}

if(Input::GetKeyDown('d'))
{
    if(BackgroundGrid::Instance()->RoomRight(this))
        {SideMovement = Vector2( 31, 0);
        hMovement = 1;
        }
}

if(Input::GetKeyDown('o'))
{
    RotateLeft();
    if( BackgroundGrid::Instance()->OverLap(_shape,_vPos,_hPos) )
        RotateRight();
}

if(Input::GetKeyDown('p'))
{
    RotateRight();
    if( BackgroundGrid::Instance()->OverLap(_shape,_vPos,_hPos) )
        RotateLeft();
}


if(Input::GetKeyDown('w'))
{
    unsigned int minimum = BackgroundGrid::Instance()->MinHeight(this) -1;
    _vPos += minimum;
    _position += Vector2( 0, -(int)( minimum*31 ) );
    _lastStepMS += _turn;
    BackgroundGrid::Instance()->SetPiece(this);
    //BackgroundGrid::Instance()->show_grid();
    //BackgroundGrid::Instance()->show_piletop();
    _sits = true;
    BackgroundGrid::Instance()->Settle();
    return;
}

if( GameTime::GetTimeMS() - _lastStepMS > _turn )
{
    if(Input::GetKey('s'))
    {
        _turn = 50;
    }

    if( BackgroundGrid::Instance()->RoomDown(this) )
    {
        _lastStepMS += _turn;
        DownMovement += Vector2( 0, -31 );
        vMovement = 1;
    }
    else
    {
        BackgroundGrid::Instance()->SetPiece(this);
        //BackgroundGrid::Instance()->show_grid();
        //BackgroundGrid::Instance()->show_piletop();
        _sits = true;
        BackgroundGrid::Instance()->Settle();
        return;
    }

}

_position += SideMovement + DownMovement;
_hPos +=hMovement;
_vPos +=vMovement;

}


void RotatableTetromino::RotateLeft(){
std::vector < std::vector <int> > aux;

int n = GetHeight();
int m = GetWidth();

aux.resize(m);

for( int i = 0; i < m; i ++ )
    aux[i].resize(n);

for( int i = 0; i < n; i ++ )
{
    for( int j = 0; j < m; j ++ )
       {
           aux[m-j-1][i] = _shape[i][j];
       }
}

_shape = aux;

switch( _rotation ){
case 0:
    {
    _rotation = 1;
    break;
    }
case 1:
    {_vPos += abs(n-m);
    _rotation = 2;
    break;
    }
case 2:
    {_vPos -= abs(n-m);
    _hPos += abs(n-m);
    _rotation = 3;
    break;
    }
case 3:
    {_hPos -= abs(n-m);
    _rotation = 0;
    break;
    }
}
_position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2( _hPos * 31, -(int)( _vPos * 31 ) );

}

void RotatableTetromino::RotateRight(){
std::vector < std::vector <int> > aux;

int n = GetHeight();
int m = GetWidth();

aux.resize(m);

for( int i = 0; i < m; i ++ )
    aux[i].resize(n);

for( int i = 0; i < n; i ++ )
{
    for( int j = 0; j < m; j ++ )
       {
           aux[j][n-i-1] = _shape[i][j];
       }
}

_shape = aux;

switch( _rotation ){
case 0:
    {_hPos += abs(n-m);
    _rotation = 3;
    break;
    }
case 3:
    {_vPos += abs(n-m);
    _hPos -= abs(n-m);
    _rotation = 2;
    break;
    }
case 2:
    {_vPos -= abs(n-m);
    _rotation = 1;
    break;
    }
case 1:
    {
    _rotation = 0;
    break;
    }
}

_position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2( _hPos * 31, -(int)(_vPos * 31 ) );

}

void RotatableTetromino::DrawShadow(){
unsigned int v = _vPos + BackgroundGrid::Instance()->MinHeight(this) -1;
unsigned int h = _hPos;
char x = GetNumber()+48;
std::string lb = "shadow";
lb += x;
x = _rotation+48;
lb += "_";
lb += x;
lb += ".png";

Image* shadow = (Image*)ResourceManager::Instance()->GetResource(lb);
Screen::Draw( shadow, Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2( h * 31, -(int)(v * 31)) );

}
