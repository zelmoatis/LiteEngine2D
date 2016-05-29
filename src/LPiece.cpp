#include "LPiece.h"

#include "ResourceManager.h"
#include "BackgroundGrid.h"
#include "Screen.h"
#include "Input.h"
#include "GameTime.h"
#include "Vector2.h"

LPiece::LPiece():RotatableTetromino()
{
_image[0] = (Image*)ResourceManager::Instance()->GetResource("piece5_0.png");
_image[1] = (Image*)ResourceManager::Instance()->GetResource("piece5_1.png");
_image[2] = (Image*)ResourceManager::Instance()->GetResource("piece5_2.png");
_image[3] = (Image*)ResourceManager::Instance()->GetResource("piece5_3.png");


_shape.resize(3);
_shape[0] = { 0, 5, 0 };
_shape[1] = { 0, 0, 5 };
_shape[2] = { 5, 5, 0 };

_position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2(_hPos * 31, -(int)(_vPos * 31));

_rotation = 0;
}

LPiece::~LPiece(){

}

unsigned int LPiece::GetHeight(){
return 3;
}

unsigned int LPiece::GetWidth(){
return 3;
}

unsigned int LPiece::GetNumber(){
return 5;
}

