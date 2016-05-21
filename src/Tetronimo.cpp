#include "Tetronimo.h"

#define INIT_POS_H 4
#define INIT_POS_V 0

Tetronimo::Tetronimo():
    _hPos(INIT_POS_H),
    _vPos(INIT_POS_V),
    _sits(false)
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

std::vector< std::pair< int, int > > Tetronimo::GetLeftSide(){
return _leftSide;
}

std::vector< std::pair< int, int > > Tetronimo::GetRightSide(){
return _rightSide;
}

std::vector< std::pair< int, int > > Tetronimo::GetDownSide(){
return _downSide;
}

std::vector< std::pair< int, int > > Tetronimo::GetTopSide(){
return _topSide;
}

unsigned int Tetronimo::GetHeight(){
}

unsigned int Tetronimo::GetWidth(){

}

bool Tetronimo::Sits(){
return _sits;
}
