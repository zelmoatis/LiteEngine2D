#include "WormPiece.h"

#include "ResourceManager.h"
#include "BackgroundGrid.h"
#include "Screen.h"
#include "Input.h"
#include "GameTime.h"
#include "Vector2.h"

WormPiece::WormPiece():RotatableTetromino()
{
_image[0] = (Image*)ResourceManager::Instance()->GetResource("piece2_0.png");
_image[1] = (Image*)ResourceManager::Instance()->GetResource("piece2_1.png");
_image[2] = (Image*)ResourceManager::Instance()->GetResource("piece2_0.png");
_image[3] = (Image*)ResourceManager::Instance()->GetResource("piece2_1.png");

_vPos++;

_shape.resize(2);
_shape[0] = { 2, 0, 2, 0 };
_shape[1] = { 0, 2, 0, 2 };

_position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2(_hPos * 31, -(int)(_vPos * 31));

_rotation = 0;
}

WormPiece::~WormPiece(){

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

unsigned int WormPiece::GetNumber(){
return 2;
}

