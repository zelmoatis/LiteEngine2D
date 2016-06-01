#include "GameOverMenu.h"
#include "ResourceManager.h"
#include "ClickableButton.h"
#include "Screen.h"

GameOverMenu* GameOverMenu::_GOM_Instance = 0;

GameOverMenu* GameOverMenu::Instance(){
if(!_GOM_Instance)
{
    _GOM_Instance = new GameOverMenu;
}
return _GOM_Instance;

}

GameOverMenu::GameOverMenu(){

_state.resize(2,false);

_image = (Image*)ResourceManager::Instance()->GetResource("game_over.png");

_position = Vector2(0,Screen::GetHeight ())+ Vector2( Screen::GetWidth() / 2 - _image->GetWidth() / 2, -100 );
float leftSpacing = (_image->GetWidth() - (int)((Image*) ResourceManager::Instance()->GetResource("RESUME.png") )->GetWidth() )/2;
_menu = new LayoutManager(_position + Vector2( leftSpacing ,-(int)_image->GetHeight()));

ClickableButton * temp;
temp = new ClickableButton( "retry", (Image*)ResourceManager::Instance()->GetResource("RETRY.png"),(Image*)ResourceManager::Instance()->GetResource("RETRY_selected.png"));

_buttonMap["retry"] = 1;
_menu->AddButton(temp);

temp = new ClickableButton( "end", (Image*)ResourceManager::Instance()->GetResource("END.png"),(Image*)ResourceManager::Instance()->GetResource("END_selected.png"));

_buttonMap["end"] = 2;
_menu->AddButton(temp);
}

GameOverMenu::~GameOverMenu(){

}

void GameOverMenu::Update(){

_menu->Update();
if(_menu->GetActivatedButton()!="0")
    _state[ _buttonMap[ _menu->GetActivatedButton() ] ] = true;

}

void GameOverMenu::Draw(){
Screen::Draw( _image, _position );
_menu->Display();
}

bool GameOverMenu::GetState( std::string button ){
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

