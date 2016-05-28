#include "TwinsPiece.h"

#include "ResourceManager.h"
#include "BackgroundGrid.h"
#include "Screen.h"
#include "Input.h"
#include "GameTime.h"
#include "Vector2.h"

TwinsPiece::TwinsPiece():RotatableTetromino()
{
_image[0] = (Image*)ResourceManager::Instance()->GetResource("piece6_0.png");
_image[1] = (Image*)ResourceManager::Instance()->GetResource("piece6_1.png");
_image[2] = (Image*)ResourceManager::Instance()->GetResource("piece6_0.png");
_image[3] = (Image*)ResourceManager::Instance()->GetResource("piece6_1.png");

_vPos++;

_shape.resize(2);
_shape[0] = { 6, 0, 6 };
_shape[1] = { 6, 0, 6 };

_position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2(_hPos * 31, -(int)(_vPos * 31));

_lastStepMS = GameTime::GetTimeMS();

_rotation = 0;
}

TwinsPiece::~TwinsPiece(){

}

unsigned int TwinsPiece::GetHeight(){
if( _rotation == 0 || _rotation == 2 )
    return 2;
return 3;
}

unsigned int TwinsPiece::GetWidth(){
if( _rotation == 0 || _rotation == 2 )
    return 3;
return 2;
}



