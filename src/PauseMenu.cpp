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

_state.resize(3,false);

_image = (Image*)ResourceManager::Instance()->GetResource("pause.png");

_position = Vector2(0,Screen::GetHeight ())+ Vector2( Screen::GetWidth() / 2 - _image->GetWidth() / 2, -100 );
float leftSpacing = (_image->GetWidth() - (int)((Image*) ResourceManager::Instance()->GetResource("RESUME.png") )->GetWidth() )/2;
_menu = new LayoutManager(_position + Vector2( leftSpacing ,-(int)_image->GetHeight()));

ClickableButton * temp;
temp = new ClickableButton( "resume", (Image*)ResourceManager::Instance()->GetResource("RESUME.png"),(Image*)ResourceManager::Instance()->GetResource("RESUME_selected.png"));

_buttonMap["resume"] = 0;
_menu->AddButton(temp);

temp = new ClickableButton( "retry", (Image*)ResourceManager::Instance()->GetResource("RETRY.png"),(Image*)ResourceManager::Instance()->GetResource("RETRY_selected.png"));

_buttonMap["retry"] = 1;
_menu->AddButton(temp);

temp = new ClickableButton( "end", (Image*)ResourceManager::Instance()->GetResource("END.png"),(Image*)ResourceManager::Instance()->GetResource("END_selected.png"));

_buttonMap["end"] = 2;
_menu->AddButton(temp);
}

PauseMenu::~PauseMenu(){

}

void PauseMenu::Update(){

_menu->Update();
if(_menu->GetActivatedButton()!="0")
    _state[ _buttonMap[ _menu->GetActivatedButton() ] ] = true;

}

void PauseMenu::Draw(){
Screen::Draw( _image, _position );
_menu->Display();
}

bool PauseMenu::GetState( std::string button ){
std::map<std::string, int>::iterator it = _buttonMap.find( button );
if( it == _buttonMap.end() )
    return false;
if(_state[ _buttonMap[button] ])
{
    _state[ _buttonMap[button] ] = false;
    _menu -> ResetButtons();
    return true;
}

return false;
}
