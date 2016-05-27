#include "NonRotatableTetromino.h"

#include "BackgroundGrid.h"
#include "Screen.h"
#include "Input.h"
#include "GameTime.h"
#include "Vector2.h"

#include <cstdlib>
#include <iostream>
#define TURN 1000

#define INIT_POS_H 4
#define INIT_POS_V 0


NonRotatableTetromino::NonRotatableTetromino():Tetromino()
{

}

NonRotatableTetromino::~NonRotatableTetromino(){
}

void NonRotatableTetromino::Draw(){
Screen::Draw( _image,_position );
}

void NonRotatableTetromino::Update(){


if(BackgroundGrid::Instance()->ReachedTop())
{
    return;
}

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

if(Input::GetKeyDown('s'))
{
    unsigned int minimum = BackgroundGrid::Instance()->MinHeight(this) -1;
    _vPos += minimum;
    _position += Vector2( 0, -(int)( minimum*31 ) );
    _lastStepMS += TURN;
    BackgroundGrid::Instance()->SetPiece(this);
    //BackgroundGrid::Instance()->show_grid();
    //BackgroundGrid::Instance()->show_piletop();
    _sits = true;
    BackgroundGrid::Instance()->Settle();
    return;
}

if( GameTime::GetTimeMS() - _lastStepMS > TURN )
{
    if( BackgroundGrid::Instance()->RoomDown(this) )
    {
        _lastStepMS += TURN;
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

