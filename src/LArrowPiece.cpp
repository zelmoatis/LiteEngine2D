#include "LArrowPiece.h"

#include "ResourceManager.h"
#include "BackgroundGrid.h"
#include "Screen.h"
#include "Input.h"
#include "GameTime.h"
#include "Vector2.h"

LArrowPiece::LArrowPiece():RotatableTetromino()
{
_image[0] = (Image*)ResourceManager::Instance()->GetResource("piece3_0.png");
_image[1] = (Image*)ResourceManager::Instance()->GetResource("piece3_1.png");
_image[2] = (Image*)ResourceManager::Instance()->GetResource("piece3_2.png");
_image[3] = (Image*)ResourceManager::Instance()->GetResource("piece3_3.png");

_vPos++;

_shape.resize(2);
_shape[0] = { 3, 3, 0 };
_shape[1] = { 3, 0, 3 };

_position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2(_hPos * 31, -(int)(_vPos * 31));

_lastStepMS = GameTime::GetTimeMS();

_rotation = 0;
}

LArrowPiece::~LArrowPiece(){

}

unsigned int LArrowPiece::GetHeight(){
if( _rotation == 0 || _rotation == 2 )
    return 2;
return 3;
}

unsigned int LArrowPiece::GetWidth(){
if( _rotation == 0 || _rotation == 2 )
    return 3;
return 2;
}





