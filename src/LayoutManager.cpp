#include "LayoutManager.h"

#include "ResourceManager.h"
#include "Vector2.h"
#include "Screen.h"

LayoutManager::LayoutManager(){
_position = Vector2( 0, Screen::GetHeight() );
}

LayoutManager::LayoutManager(const Vector2& pos){
_position = pos;
}

LayoutManager::~LayoutManager(){

}

void LayoutManager::AddButton( ClickableButton * button ){
if( _buttons.size() == 0 )
{
    button->SetPosition(_position);
}
else
{
    button->SetPosition( _buttons[_buttons.size() - 1] -> GetPosition() + Vector2( 0, -( int )( _buttons[_buttons.size() - 1] -> GetHeight() ) ) );
}
_buttons.push_back(button);
}

void LayoutManager::Update(){

    for (auto it : _buttons)
        {
            it->Update ();
        }

}

void LayoutManager::ResetButtons(){

    for (auto it : _buttons)
        {
            it->Reset ();
        }
}

void LayoutManager::Display(){

for (auto it : _buttons) {
		it->Draw ();
	}

}

std::string LayoutManager::GetActivatedButton(){

for (auto it : _buttons) {
    if( it->Activated() )
        return it->GetName();
    }
return "none";
}
