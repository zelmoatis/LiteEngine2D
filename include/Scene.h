#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "SceneObject.h"
#include "Tetromino.h"
#include "Player.h"

class Scene
{
private:
    Tetromino * _currentPiece;
    Player * _player;
    unsigned int _pauseTimeMS;
    bool _running;
    bool _paused;

public:
	Scene ();
	~Scene ();

	void Update ();
	void Display ();

	void Clear ();
};

#endif
