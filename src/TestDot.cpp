#include "TestDot.h"

#include "Resources.h"

#include "BackgroundGrid.h"
#include "Screen.h"
#include "Input.h"
#include "GameTime.h"
#include "Vector2.h"

TestDot::TestDot():NonRotatableTetronimo()

{
_vPos += 2;
_image = Resources::LoadImage("Assets/Images/dot_2.png");

_shape.resize(1);
_shape[0].resize(1,1);
_rightSide = {0};
_leftSide = {0};
_downSide = {0};
_topSide = {0};
_position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2( 4+_hPos * _image->GetWidth(), -(int)(4+_vPos *_image->GetHeight()));

_lastStepMS = GameTime::GetTimeMS();
}

TestDot::~TestDot(){
delete _image;
}
