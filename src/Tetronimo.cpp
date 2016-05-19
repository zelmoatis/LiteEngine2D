#include "Tetronimo.h"

#define INIT_POS_H 4
#define INIT_POS_V 0

Tetronimo::Tetronimo():
    _hPos(INIT_POS_H),
    _vPos(INIT_POS_V)
    {

}

Tetronimo::~Tetronimo(){

}

void Tetronimo::Draw(){

}

void Tetronimo::Update(){

}

unsigned int Tetronimo::GetH(){
return _hPos;
}

unsigned int Tetronimo::GetV(){
return _vPos;
}

std::vector< std::vector <int> > Tetronimo::GetShape(){
return _shape;
}

std::vector<int> Tetronimo::GetLeftSide(){
return _leftSide;
}

std::vector<int> Tetronimo::GetRightSide(){
return _rightSide;
}

std::vector<int> Tetronimo::GetDownSide(){
return _downSide;
}

std::vector<int> Tetronimo::GetTopSide(){
return _topSide;
}

unsigned int Tetronimo::GetHeight(){
return _shape.size();
}

unsigned int Tetronimo::GetWidth(){
return _shape[0].size();
}
