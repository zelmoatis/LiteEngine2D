#ifndef TETRONIMO_H
#define TETRONIMO_H

#include "SceneObject.h"

#include <vector>

class Tetronimo: public SceneObject{
protected:
    std::vector< std::vector< int > > _shape;//every piece has an individual number used for its shape
    unsigned int _hPos, _vPos;
    //sides save the position of the significant dots
    //on the specified direction
    std::vector< std::pair< int, int > > _leftSide;
    std::vector< std::pair< int, int > > _rightSide;
    std::vector< std::pair< int, int > > _downSide;
    std::vector< std::pair< int, int > > _topSide;
    int _lastStepMS;
    bool _sits;
public:
    Tetronimo();
    virtual ~Tetronimo();
    virtual void Draw();
    virtual void Update();
    virtual unsigned int GetH();
    virtual unsigned int GetV();
    virtual std::vector< std::vector <int> > GetShape();//maybe can be improved by returning only a reference or pointer
    virtual std::vector< std::pair< int, int > > GetLeftSide();
    virtual std::vector< std::pair< int, int > > GetRightSide();
    virtual std::vector< std::pair< int, int > > GetDownSide();
    virtual std::vector< std::pair< int, int > > GetTopSide();
    virtual unsigned int GetHeight();
    virtual unsigned int GetWidth();
    bool Sits();
};


#endif // TETRONIMO

