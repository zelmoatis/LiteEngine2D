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
    unsigned int _pauseTimeMS;
    bool _running;
    bool _paused;
    void InitializePieces();
public:
	Scene ();
	~Scene ();
    Player * _player;
	void Update ();
	void Display ();
    void Reset ();
	void Clear ();
};

#endif
