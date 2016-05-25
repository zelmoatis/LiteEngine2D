#include "Scene.h"
#include "BackgroundGrid.h"
#include "BallObject.h"
#include "ExplosionPiece.h"
#include "WormPiece.h"

#include "PieceGenerator.h"
#include <time.h>

Scene::Scene ()
{
    srand(time(NULL));

	_currentPiece = PieceGenerator::Instance()->PopPiece();
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
        _currentPiece = PieceGenerator::Instance()->PopPiece();
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
