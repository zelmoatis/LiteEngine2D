#include "RArrowPiece.h"

#include "ResourceManager.h"
#include "BackgroundGrid.h"
#include "Screen.h"
#include "Input.h"
#include "GameTime.h"
#include "Vector2.h"

RArrowPiece::RArrowPiece():RotatableTetromino()
{
_image[0] = (Image*)ResourceManager::Instance()->GetResource("piece4_0.png");
_image[1] = (Image*)ResourceManager::Instance()->GetResource("piece4_1.png");
_image[2] = (Image*)ResourceManager::Instance()->GetResource("piece4_2.png");
_image[3] = (Image*)ResourceManager::Instance()->GetResource("piece4_3.png");

_vPos++;

_shape.resize(2);
_shape[0] = { 0, 4, 4 };
_shape[1] = { 4, 0, 4 };

_position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2(_hPos * 31, -(int)(_vPos * 31));

_rotation = 0;

}

RArrowPiece::~RArrowPiece(){

}

unsigned int RArrowPiece::GetHeight(){
if( _rotation == 0 || _rotation == 2 )
    return 2;
return 3;
}

unsigned int RArrowPiece::GetWidth(){
if( _rotation == 0 || _rotation == 2 )
    return 3;
return 2;
}

unsigned int RArrowPiece::GetNumber(){
return 4;
}


