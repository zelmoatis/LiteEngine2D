#include "WormPiece.h"

#include "Resources.h"

#include "BackgroundGrid.h"
#include "Screen.h"
#include "Input.h"
#include "GameTime.h"
#include "Vector2.h"

WormPiece::WormPiece():RotatableTetronimo()
{
_image = Resources::LoadImage("Assets/Images/badris/2Piece_0.png");

_vPos++;

_shape.resize(2);
_shape[0] = { 2, 0, 2, 0 };
_shape[1] = { 0, 2, 0, 2 };

_leftSide = { std::make_pair(0,0), std::make_pair(1,1) };
_rightSide = { std::make_pair(0,2), std::make_pair(1,3) };
_downSide = { std::make_pair(0,0),std::make_pair(1,1),std::make_pair(0,2),std::make_pair(1,3) };
_topSide = { std::make_pair(0,0),std::make_pair(1,1),std::make_pair(0,2),std::make_pair(1,3) };

_position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2( 4+_hPos * 23, -(int)(4+_vPos * 22));

_lastStepMS = GameTime::GetTimeMS();

_rotation = 0;
}

WormPiece::~WormPiece(){
delete _image;
}

unsigned int WormPiece::GetHeight(){
if( _rotation == 0 || _rotation == 2 )
    return 2;
return 4;
}

unsigned int WormPiece::GetWidth(){
if( _rotation == 0 || _rotation == 2 )
    return 4;
return 2;
}

void WormPiece::RotateLeft(){

switch (_rotation)
{
case 0:
    {
    _position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2( 4+_hPos * 23, -(int)(2+_vPos * 22 ) );

    _shape.resize(4);
    _shape[0] = { 0, 2,};
    _shape[1] = { 2, 0,};
    _shape[2] = { 0, 2,};
    _shape[3] = { 2, 0,};

    _leftSide = { std::make_pair(0,1),std::make_pair(1,0),std::make_pair(2,1),std::make_pair(3,0) };
    _rightSide = { std::make_pair(0,1),std::make_pair(1,0),std::make_pair(2,1),std::make_pair(3,0) };
    _downSide = { std::make_pair(3,0), std::make_pair(2,1) };
    _topSide = { std::make_pair(3,0), std::make_pair(2,1) };

    _image = Resources::LoadImage("Assets/Images/badris/2Piece_1.png");

    _rotation = 1;
    break;
    }
    case 1:
    {
    _vPos +=2;

    _position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2( 4+_hPos * 23, -(int)(4+_vPos * 22) );

    _leftSide = { std::make_pair(0,0), std::make_pair(1,1) };
    _rightSide = { std::make_pair(0,2), std::make_pair(1,3) };
    _downSide = { std::make_pair(0,0),std::make_pair(1,1),std::make_pair(0,2),std::make_pair(1,3) };
    _topSide = { std::make_pair(0,0),std::make_pair(1,1),std::make_pair(0,2),std::make_pair(1,3) };

    _shape.resize(2);
    _shape[0] = { 2, 0, 2, 0 };
    _shape[1] = { 0, 2, 0, 2 };

    _image = Resources::LoadImage("Assets/Images/badris/2Piece_0.png");

    _rotation = 2;
    break;
    }
    case 2:
    {
    _vPos -=2;
    _hPos +=2;

    _position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2( 4+_hPos * 23, -(int)(2+_vPos * 22));

    _shape.resize(4);
    _shape[0] = { 0, 2,};
    _shape[1] = { 2, 0,};
    _shape[2] = { 0, 2,};
    _shape[3] = { 2, 0,};

    _leftSide = { std::make_pair(0,1),std::make_pair(1,0),std::make_pair(2,1),std::make_pair(3,0) };
    _rightSide = { std::make_pair(0,1),std::make_pair(1,0),std::make_pair(2,1),std::make_pair(3,0) };
    _downSide = { std::make_pair(3,0), std::make_pair(2,1) };
    _topSide = { std::make_pair(3,0), std::make_pair(2,1) };

    _image = Resources::LoadImage("Assets/Images/badris/2Piece_1.png");

    _rotation = 3;
    break;
    }
    case 3:
    {
    _hPos -=2;

    _position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2( 4+_hPos * 23, -(int)(4+_vPos * 22));

    _shape.resize(2);
    _shape[0] = { 2, 0, 2, 0 };
    _shape[1] = { 0, 2, 0, 2 };

    _leftSide = { std::make_pair(0,0), std::make_pair(1,1) };
    _rightSide = { std::make_pair(0,2), std::make_pair(1,3) };
    _downSide = { std::make_pair(0,0),std::make_pair(1,1),std::make_pair(0,2),std::make_pair(1,3) };
    _topSide = { std::make_pair(0,0),std::make_pair(1,1),std::make_pair(0,2),std::make_pair(1,3) };

    _image = Resources::LoadImage("Assets/Images/badris/2Piece_0.png");

    _rotation = 0;
    break;
    }
}

}

void WormPiece::RotateRight(){
switch(_rotation)
{

case 0:
    {
    _hPos += 2;

    _position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2( 4+_hPos * 23, -(int)(2+_vPos * 22));

    _shape.resize(4);
    _shape[0] = { 0, 2,};
    _shape[1] = { 2, 0,};
    _shape[2] = { 0, 2,};
    _shape[3] = { 2, 0,};

    _leftSide = { std::make_pair(0,1),std::make_pair(1,0),std::make_pair(2,1),std::make_pair(3,0) };
    _rightSide = { std::make_pair(0,1),std::make_pair(1,0),std::make_pair(2,1),std::make_pair(3,0) };
    _downSide = { std::make_pair(3,0), std::make_pair(2,1) };
    _topSide = { std::make_pair(3,0), std::make_pair(2,1) };

    _image = Resources::LoadImage("Assets/Images/badris/2Piece_1.png");

    _rotation = 1;
    break;
    }
    case 1:
    {
    _vPos +=2;
    _hPos -=2;

    _position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2( 4+_hPos * 23, -(int)(4+_vPos * 22));

    _shape.resize(2);
    _shape[0] = { 2, 0, 2, 0 };
    _shape[1] = { 0, 2, 0, 2 };

    _image = Resources::LoadImage("Assets/Images/badris/2Piece_0.png");

    _leftSide = { std::make_pair(0,0), std::make_pair(1,1) };
    _rightSide = { std::make_pair(0,2), std::make_pair(1,3) };
    _downSide = { std::make_pair(0,0),std::make_pair(1,1),std::make_pair(0,2),std::make_pair(1,3) };
    _topSide = { std::make_pair(0,0),std::make_pair(1,1),std::make_pair(0,2),std::make_pair(1,3) };

    _rotation = 2;
    break;
    }
    case 2:
    {
    _vPos -=2;

    _position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2( 4+_hPos * 23, -(int)(2+_vPos * 22));

    _shape.resize(4);
    _shape[0] = { 0, 2,};
    _shape[1] = { 2, 0,};
    _shape[2] = { 0, 2,};
    _shape[3] = { 2, 0,};

    _leftSide = { std::make_pair(0,1),std::make_pair(1,0),std::make_pair(2,1),std::make_pair(3,0) };
    _rightSide = { std::make_pair(0,1),std::make_pair(1,0),std::make_pair(2,1),std::make_pair(3,0) };
    _downSide = { std::make_pair(3,0), std::make_pair(2,1) };
    _topSide = { std::make_pair(3,0), std::make_pair(2,1) };

    _image = Resources::LoadImage("Assets/Images/badris/2Piece_1.png");

    _rotation = 3;
    break;
    }
    case 3:
    {
    _position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2( 4+_hPos * 23, -(int)(4+_vPos * 22));

    _shape.resize(2);
    _shape[0] = { 2, 0, 2, 0 };
    _shape[1] = { 0, 2, 0, 2 };

    _leftSide = { std::make_pair(0,0), std::make_pair(1,1) };
    _rightSide = { std::make_pair(0,2), std::make_pair(1,3) };
    _downSide = { std::make_pair(0,0),std::make_pair(1,1),std::make_pair(0,2),std::make_pair(1,3) };
    _topSide = { std::make_pair(0,0),std::make_pair(1,1),std::make_pair(0,2),std::make_pair(1,3) };

    _image = Resources::LoadImage("Assets/Images/badris/2Piece_0.png");

    _rotation = 0;
    break;
    }
}

}
