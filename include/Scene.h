#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "SceneObject.h"
#include "Tetronimo.h"

class Scene
{
private:
    Tetronimo * _currentPiece;
public:
	Scene ();
	~Scene ();

	void Update ();
	void Display ();

	void Clear ();
};

#endif
