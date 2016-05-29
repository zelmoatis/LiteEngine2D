#include "PauseMenu.h"
#include "ResourceManager.h"
#include "ClickableButton.h"
#include "Screen.h"

PauseMenu* PauseMenu::_PM_Instance = 0;

PauseMenu* PauseMenu::Instance(){
if(!_PM_Instance)
{
    _PM_Instance = new PauseMenu;
}
return _PM_Instance;

}

PauseMenu::PauseMenu(){

_state = false;

_image = (Image*)ResourceManager::Instance()->GetResource("temp_pause.png");

_position = Vector2(0,Screen::GetHeight ())+ Vector2( Screen::GetWidth() / 2 - _image->GetWidth() / 2, -100 );
_menu = new LayoutManager(_position + Vector2(0,-80));

ClickableButton * resume;
resume = new ClickableButton( "resume", (Image*)ResourceManager::Instance()->GetResource("temp_resume.png"));

_menu->AddButton(resume);

}

PauseMenu::~PauseMenu(){

}

void PauseMenu::Update(){

_menu->Update();
if(_menu->GetActivatedButton() == "resume")
    {
        _state = true;
    }
else
    _state = false;
}

void PauseMenu::Draw(){
Screen::Draw( _image, _position );
_menu->Display();
}

bool PauseMenu::GetState(){
if(_state)
{
    _menu -> ResetButtons();
    return true;
}
return false;
}
