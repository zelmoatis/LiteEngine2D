#include "Scene.h"
#include "BackgroundGrid.h"
#include "PieceGenerator.h"
#include "Input.h"
#include "GameTime.h"
#include "PauseMenu.h"
#include "GameOverMenu.h"

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
    if( !_running )
    {
        GameOverMenu::Instance()->Update();
        if( GameOverMenu::Instance()->GetState("retry") )
        {
            _player->SaveScore();
            Reset();
        }
        return;
    }
    if( _paused )
    {
        PauseMenu::Instance()->Update();
        if( Input::GetKeyDown (27) || PauseMenu::Instance()->GetState("resume") )
            {
                _currentPiece -> SetLastStep( GameTime::GetTimeMS() - (_pauseTimeMS - _currentPiece -> GetLastStep() ) );
                _player -> SetStart( GameTime::GetTimeMS() - _pauseTimeMS + _player -> GetStart() );
                _paused = false;
            }
        if( PauseMenu::Instance()->GetState("retry") )
            Reset();
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
        if( Input::GetKeyDown (27) )
        {
            _pauseTimeMS = GameTime::GetTimeMS();
            _paused = true;
        }
    }
}

void Scene::Display ()
{
    if( _paused )
    {
        PauseMenu::Instance()->Draw();
    }
    else
    {
	BackgroundGrid::Instance()->Draw();

	_currentPiece->Draw();
	PieceGenerator::Instance()->Draw();
    }
	if( !_running )
    {
        GameOverMenu::Instance()->Draw();
    }
}

void Scene::Reset ()
{
    Clear();
    _running = true;
    _paused = false;
    _player = new Player;
    PieceGenerator::Instance()->Reset();
    BackgroundGrid::Instance()->Reset();
    _currentPiece = PieceGenerator::Instance()->PopPiece();
}

void Scene::Clear ()
{
	delete _currentPiece;
}
