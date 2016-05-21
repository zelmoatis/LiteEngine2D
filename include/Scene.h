#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "SceneObject.h"
#include "Tetromino.h"

class Scene
{
private:
    Tetromino * _currentPiece;
public:
	Scene ();
	~Scene ();

	void Update ();
	void Display ();

	void Clear ();
};

#endif
