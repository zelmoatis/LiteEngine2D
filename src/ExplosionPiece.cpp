#include "ExplosionPiece.h"

#include "Resources.h"

#include "BackgroundGrid.h"
#include "Screen.h"
#include "Input.h"
#include "GameTime.h"
#include "Vector2.h"

ExplosionPiece::ExplosionPiece():NonRotatableTetronimo()
{
_image = Resources::LoadImage("Assets/Images/badris/1Piece.png");

_shape.resize(3);
_shape[0] = { 1, 0, 1 };
_shape[1] = { 0, 0, 0 };
_shape[2] = { 1, 0, 1 };

_leftSide = { 0, 2 };
_rightSide = { 0, 2 };
_downSide = { 0, 2 };
_topSide = { 0, 2 };
_position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2( 4+_hPos * 23, -(int)(4+_vPos * 22));

_lastStepMS = GameTime::GetTimeMS();
}

ExplosionPiece::~ExplosionPiece(){
delete _image;
}
