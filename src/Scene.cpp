#include "Scene.h"
#include "BackgroundGrid.h"
#include "PieceGenerator.h"
#include "Input.h"
#include "GameTime.h"
#include "PauseMenu.h"

Scene::Scene ()
{
    _running = true;
    _paused = false;
	_currentPiece = PieceGenerator::Instance()->PopPiece();
	_player = new Player;
}

Scene::~Scene ()
{
	Clear ();
}

void Scene::Update ()
{
    if( _paused )
    {
        PauseMenu::Instance()->Update();
        if( Input::GetKeyDown('`') || PauseMenu::Instance()->GetState() )
            {
                _currentPiece -> SetLastStep( GameTime::GetTimeMS() - (_pauseTimeMS - _currentPiece -> GetLastStep() ) );
                _player -> SetStart( GameTime::GetTimeMS() - _pauseTimeMS + _player -> GetStart() );
                _paused = false;
            }
        return;
    }
    if( _running )
    {
        BackgroundGrid::Instance()->Update();
        _currentPiece->Update();
        _player->Update();
        if( _currentPiece->Sits() )
        {
            delete _currentPiece;
            _currentPiece = PieceGenerator::Instance()->PopPiece();
        }
        if( BackgroundGrid::Instance()->ReachedTop() )
        {
            _running = false;
        }
        if( Input::GetKeyDown('`'))
            {
                _pauseTimeMS = GameTime::GetTimeMS();
                _paused = true;
            }
    }
}

void Scene::Display ()
{

	BackgroundGrid::Instance()->Draw();

	_currentPiece->Draw();

	PieceGenerator::Instance()->Draw();
    if( _paused )
    {
        PauseMenu::Instance()->Draw();
    }
    else
        _player->Draw();
}

void Scene::Clear ()
{

	delete _currentPiece;

}
