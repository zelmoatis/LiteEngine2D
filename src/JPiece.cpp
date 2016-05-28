#include "JPiece.h"

#include "ResourceManager.h"
#include "BackgroundGrid.h"
#include "Screen.h"
#include "Input.h"
#include "GameTime.h"
#include "Vector2.h"

JPiece::JPiece():RotatableTetromino()
{
_image[0] = (Image*)ResourceManager::Instance()->GetResource("piece7_0.png");
_image[1] = (Image*)ResourceManager::Instance()->GetResource("piece7_1.png");
_image[2] = (Image*)ResourceManager::Instance()->GetResource("piece7_2.png");
_image[3] = (Image*)ResourceManager::Instance()->GetResource("piece7_3.png");


_shape.resize(3);
_shape[0] = { 0, 7, 0 };
_shape[1] = { 7, 0, 0 };
_shape[2] = { 0, 7, 7 };

_position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2(_hPos * 31, -(int)(_vPos * 31));

_lastStepMS = GameTime::GetTimeMS();

_rotation = 0;
}

JPiece::~JPiece(){

}

unsigned int JPiece::GetHeight(){
return 3;
}

unsigned int JPiece::GetWidth(){
return 3;
}

unsigned int JPiece::GetNumber(){
return 7;
}



