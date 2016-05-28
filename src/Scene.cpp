#include "Scene.h"
#include "BackgroundGrid.h"
#include "PieceGenerator.h"
#include <time.h>

Scene::Scene ()
{
    srand(time(NULL));
    _running = true;
	_currentPiece = PieceGenerator::Instance()->PopPiece();
}

Scene::~Scene ()
{
	Clear ();
}

void Scene::Update ()
{
    if( Scene::_running == true )
    {
        BackgroundGrid::Instance()->Update();
        _currentPiece->Update();
        if( _currentPiece->Sits() )
        {
            delete _currentPiece;
            _currentPiece = PieceGenerator::Instance()->PopPiece();
        }
        if( BackgroundGrid::Instance()->ReachedTop() )
        {
            _running = false;
        }
    }
}

void Scene::Display ()
{
	BackgroundGrid::Instance()->Draw();

	_currentPiece->Draw();

	PieceGenerator::Instance()->Draw();

}

void Scene::Clear ()
{

	delete _currentPiece;

}
