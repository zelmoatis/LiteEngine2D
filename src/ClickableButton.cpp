#include "ClickableButton.h"

#include "Screen.h"
#include "Input.h"

ClickableButton::ClickableButton(){
_activated = false;
}

ClickableButton::ClickableButton( const std::string& name, Image * image ){
_name = name;
_image = image;
}

ClickableButton::~ClickableButton(){

}

void ClickableButton::Draw(){
Screen::Draw( _image, _position );
}

void ClickableButton::Update(){

Vector2 area = Vector2( _image->GetWidth(), -(int)(_image->GetHeight()) );
Vector2 temp = Vector2(Input::GetMousePosition().GetX(), Screen::GetHeight() - Input::GetMousePosition().GetY());
Vector2 dif;
dif = ( temp - _position ) - area;
if( dif.GetX() < 0 && dif.GetY() > 0 && dif.Magnitude() <= area.Magnitude() )
{
    if( Input::GetMouseButton( Uint8(SDL_BUTTON_LEFT) ) )//not sure about mouse button
    {
        _activated = true;
    }
}

}

bool ClickableButton::Activated(){
return _activated;
}

void ClickableButton::SetPosition( const Vector2& position ){
_position = position;
}

unsigned int ClickableButton::GetHeight(){
return _image->GetHeight();
}

unsigned int ClickableButton::GetWidth(){
return _image->GetWidth();
}

Vector2 ClickableButton::GetPosition(){
return _position;
}

std::string ClickableButton::GetName(){
return _name;
}
void ClickableButton::Reset(){
_activated = false;
}
