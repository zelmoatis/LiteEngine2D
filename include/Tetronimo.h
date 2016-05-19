#ifndef TETRONIMO_H
#define TETRONIMO_H

#include "SceneObject.h"

#include <vector>

class Tetronimo: public SceneObject{
protected:
    std::vector< std::vector< int > > _shape;//every piece has an individual number used for its shape
    unsigned int _hPos, _vPos;
    std::vector< int > _leftSide;
    std::vector< int > _rightSide;
    std::vector< int > _downSide;
    std::vector< int > _topSide;
public:
    Tetronimo();
    virtual ~Tetronimo();
    virtual void Draw();
    virtual void Update();
    virtual unsigned int GetH();
    virtual unsigned int GetV();
    virtual std::vector< std::vector <int> > GetShape();//maybe can be improved by returning only a reference or pointer
    virtual std::vector<int> GetLeftSide();
    virtual std::vector<int> GetRightSide();
    virtual std::vector<int> GetDownSide();
    virtual std::vector<int> GetTopSide();
    virtual unsigned int GetHeight();
    virtual unsigned int GetWidth();
};


#endif // TETRONIMO

