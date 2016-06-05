#include "Scene.h"
#include "BackgroundGrid.h"

#include "PieceGenerator.h"
#include "Tetromino.h"
#include "ExplosionPiece.h"
#include "WormPiece.h"
#include "JPiece.h"
#include "TwinsPiece.h"
#include "RArrowPiece.h"
#include "LArrowPiece.h"
#include "LPiece.h"

#include "PieceGenerator.h"
#include "Input.h"
#include "GameTime.h"
#include "PauseMenu.h"
#include "GameOverMenu.h"
#include "UpcomingList.h"

void Scene::InitializePieces(){

PieceGenerator::Instance()->Register("ExplosionPiece",&ExplosionPiece::Create);
PieceGenerator::Instance()->Register("WormPiece",&WormPiece::Create);
PieceGenerator::Instance()->Register("RArrowPiece",&RArrowPiece::Create);
PieceGenerator::Instance()->Register("LArrowPiece",&LArrowPiece::Create);
PieceGenerator::Instance()->Register("LPiece",&LPiece::Create);
PieceGenerator::Instance()->Register("TwinsPiece",&TwinsPiece::Create);
PieceGenerator::Instance()->Register("JPiece",&JPiece::Create);

}
Scene::Scene ()
{
    InitializePieces();
    _running = true;
    _paused = false;
	_currentPiece = UpcomingList::Instance()->PopPiece();
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
            _currentPiece = UpcomingList::Instance()->PopPiece();
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
	UpcomingList::Instance()->Draw();
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
    UpcomingList::Instance()->Reset();
    BackgroundGrid::Instance()->Reset();
    _currentPiece = UpcomingList::Instance()->PopPiece();
}

void Scene::Clear ()
{
	delete _currentPiece;
}
