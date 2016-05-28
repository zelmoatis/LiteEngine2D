#include "ExplosionPiece.h"

#include "ResourceManager.h"
#include "BackgroundGrid.h"
#include "Screen.h"
#include "Input.h"
#include "GameTime.h"
#include "Vector2.h"

ExplosionPiece::ExplosionPiece():NonRotatableTetromino()
{
_image = (Image*)ResourceManager::Instance()->GetResource("piece1_0.png");

_shape.resize(3);
_shape[0] = { 1, 0, 1 };
_shape[1] = { 0, 0, 0 };
_shape[2] = { 1, 0, 1 };


_position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2(_hPos * 31, -(int)(_vPos * 31));

_lastStepMS = GameTime::GetTimeMS();
}

ExplosionPiece::~ExplosionPiece(){

}

unsigned int ExplosionPiece::GetHeight(){
return 3;
}

unsigned int ExplosionPiece::GetWidth(){
return 3;
}

unsigned int ExplosionPiece::GetNumber(){
return 1;
}
