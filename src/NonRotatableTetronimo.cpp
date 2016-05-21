#include "NonRotatableTetronimo.h"

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


NonRotatableTetronimo::NonRotatableTetronimo():Tetronimo()
{

}

NonRotatableTetronimo::~NonRotatableTetronimo(){

}

void NonRotatableTetronimo::Draw(){
Screen::Draw( _image,_position );
}

void NonRotatableTetronimo::Update(){

unsigned int top = BackgroundGrid::Instance()->GetPileTop();
if(top<3)
{
    std::cout<<"GAME OVER ";
    return;
}

    Vector2 SideMovement = Vector2::Zero;
    Vector2 DownMovement = Vector2::Zero;
    int hMovement = 0, vMovement = 0;

if(GetV()+GetHeight()-1<top)
{
    if(Input::GetKeyDown('a'))
    {
        if(BackgroundGrid::Instance()->RoomLeft(this))
            {SideMovement = Vector2( -23, 0 );
            hMovement = -1;
            }
    }

    if(Input::GetKeyDown('d'))
    {
        if(BackgroundGrid::Instance()->RoomRight(this))
            {SideMovement = Vector2( 23, 0);
            hMovement = 1;
            }
    }

    if(Input::GetKeyDown('s'))
    {

            unsigned int minimum = BackgroundGrid::Instance()->MinHeight(this) -1;
            _vPos += minimum;
            _position += Vector2( 0, -(int)( minimum*22 ) );
            _lastStepMS += TURN;
            BackgroundGrid::Instance()->SetPiece(this);
            //BackgroundGrid::Instance()->show_grid();
            //BackgroundGrid::Instance()->show_piletop();
            _sits = true;
            BackgroundGrid::Instance()->Settle();
            /*
            //this is where this piece disappears and another one is spawned
            //instead, we move this one to initial position and reset _lastStepMS
            _lastStepMS = GameTime::GetTimeMS();
            _vPos = INIT_POS_V;
            _hPos = INIT_POS_H;
            _position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2( 4+_hPos * 23, -(int)(4+_vPos * 22));
            */
            return;

    }
}
else
{
    if(Input::GetKeyDown('a'))
    {
        if(BackgroundGrid::Instance()->RoomLeft(this)&&BackgroundGrid::Instance()->RoomLeftInside(this))
            {SideMovement = Vector2( -23, 0 );
            hMovement = -1;
            }
    }

    if(Input::GetKeyDown('d'))
    {
        if(BackgroundGrid::Instance()->RoomRight(this)&&BackgroundGrid::Instance()->RoomRightInside(this))
            {SideMovement = Vector2( 23, 0);
            hMovement = 1;
            }
    }

    if(Input::GetKeyDown('s'))
    {
        {
            unsigned int minimum = BackgroundGrid::Instance()->MinHeight(this) -1;
            _vPos += minimum;
            _position += Vector2( 0, -(int)( minimum*22 ) );
            _lastStepMS += TURN;
            BackgroundGrid::Instance()->SetPiece(this);
            //BackgroundGrid::Instance()->show_grid();
            //BackgroundGrid::Instance()->show_piletop();
            _sits = true;
            BackgroundGrid::Instance()->Settle();
            /*
            //this is where this piece disappears and another one is spawned
            //instead, we move this one to initial position and reset _lastStepMS
            _lastStepMS = GameTime::GetTimeMS();
            _vPos = INIT_POS_V;
            _hPos = INIT_POS_H;
            _position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2( 4+_hPos * 23, -(int)(4+_vPos * 22));
            */
            return;
        }
    }
}

if( GameTime::GetTimeMS() - _lastStepMS > TURN )
{
    if( GetV()+GetHeight()-1<top )
    {
        if( BackgroundGrid::Instance()->RoomDown(this) )
        {
            _lastStepMS += TURN;
            DownMovement += Vector2( 0, -22 );
            vMovement = 1;
        }
        else
        {
            BackgroundGrid::Instance()->SetPiece(this);
            //BackgroundGrid::Instance()->show_grid();
            //BackgroundGrid::Instance()->show_piletop();
            _sits = true;
            BackgroundGrid::Instance()->Settle();
            /*
            //this is where this piece disappears and another one is spawned
            //instead, we move this one to initial position and reset _lastStepMS
            _lastStepMS = GameTime::GetTimeMS();
            _vPos = INIT_POS_V;
            _hPos = INIT_POS_H;
            _position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2( 4+_hPos * 23, -(int)(4+_vPos * 22));
            */
            return;
        }

    }
    else
    {
        if( BackgroundGrid::Instance()->RoomDownInside(this) && BackgroundGrid::Instance()->RoomDown(this) )
        {
            _lastStepMS += TURN;
            DownMovement += Vector2( 0, -22 );
            vMovement = 1;
        }
        else
        {
            BackgroundGrid::Instance()->SetPiece(this);
            //BackgroundGrid::Instance()->show_grid();
            //BackgroundGrid::Instance()->show_piletop();
            _sits = true;
            BackgroundGrid::Instance()->Settle();
            /*
            //this is where this piece disappears and another one is spawned
            //instead, we move this one to initial position and reset _lastStepMS
            _lastStepMS = GameTime::GetTimeMS();
            _vPos = INIT_POS_V;
            _hPos = INIT_POS_H;
            _position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2( 4+_hPos * 23, -(int)(4+_vPos * 22));
            */
            return;
        }

    }

}

_position += SideMovement + DownMovement;
_hPos +=hMovement;
_vPos +=vMovement;
}

