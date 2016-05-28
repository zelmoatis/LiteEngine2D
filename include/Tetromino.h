#ifndef TETROMINO_H
#define TETROMINO_H

#include "SceneObject.h"

#include <vector>

class Tetromino: public SceneObject{
protected:
    std::vector< std::vector< int > > _shape;//every piece has an individual number used for its shape
    unsigned int _hPos, _vPos;
    int _lastStepMS;
    bool _sits;
public:
    Tetromino();
    virtual ~Tetromino();
    virtual void Draw();
    virtual void Update();
    virtual unsigned int GetH();
    virtual unsigned int GetV();
    virtual std::vector< std::vector <int> > GetShape();//maybe can be improved by returning only a reference or pointer
    virtual unsigned int GetHeight();
    virtual unsigned int GetWidth();
    virtual unsigned int GetNumber();
    bool Sits();
};


#endif // TETROMINO

