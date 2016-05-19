#include "Scene.h"
#include "BackgroundGrid.h"
#include "TestDot.h"
#include "BallObject.h"
#include "ExplosionPiece.h"

Scene::Scene ()
{
	// Hardcoded construction of a new BallObject in the scene constructor
	// TODO: This need to be deleted (even as an example)

	_objects.push_back (BackgroundGrid::Instance());
	_objects.push_back( new ExplosionPiece );
	// _objects.push_back (new BallObject ());
	// _objects.push_back (new BallObject ());
	// _objects.push_back (new BallObject ());
	// _objects.push_back (new BallObject ());
	// _objects.push_back (new BallObject ());
}

Scene::~Scene ()
{
	Clear ();
}

void Scene::Update ()
{
	for (auto it : _objects) {
		it->Update ();
	}
}

void Scene::Display ()
{
	for (auto it : _objects) {
		it->Draw ();
	}
}

void Scene::Clear ()
{
	for (auto it : _objects) {
		delete it;
	}
}
