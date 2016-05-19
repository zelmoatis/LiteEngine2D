#include "BasicSquare.h"
#include "BackgroundGrid.h"

#include "Resources.h"

#include "Screen.h"
#include "Input.h"
#include "GameTime.h"
#include "Vector2.h"


#include <cstdlib>

#define INIT_POS 4
#define SQUARE_SPEED 1000

BasicSquare::BasicSquare ():
	_speed (SQUARE_SPEED),
	_hPos(INIT_POS),_vPos(0)
{
_image = Resources::LoadImage("Assets/Images/dot.jpg");



}

BasicSquare::~BasicSquare(){
delete _image;
}

void BasicSquare::Draw(){

}

void BasicSquare::Update(){

}
