#include "Scene.h"
#include "BackgroundGrid.h"
#include "BallObject.h"
#include "ExplosionPiece.h"
#include "WormPiece.h"
#include <time.h>

Scene::Scene ()
{
    srand(time(NULL));

	if( rand()%2 == 0 )
        _currentPiece = new WormPiece;
    else
        _currentPiece = new ExplosionPiece;
}

Scene::~Scene ()
{
	Clear ();
}

void Scene::Update ()
{
	BackgroundGrid::Instance()->Update();

	_currentPiece->Update();

    if( _currentPiece->Sits() )
    {
        delete _currentPiece;
        if( rand()%2 == 0 )
            _currentPiece = new WormPiece;
        else
            _currentPiece = new ExplosionPiece;
    }
}

void Scene::Display ()
{
	BackgroundGrid::Instance()->Draw();

	_currentPiece->Draw();

}

void Scene::Clear ()
{

	delete _currentPiece;

}
