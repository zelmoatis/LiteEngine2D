#include "Tetromino.h"

#define INIT_POS_H 4
#define INIT_POS_V 0

Tetromino::Tetromino():
    _hPos(INIT_POS_H),
    _vPos(INIT_POS_V),
    _sits(false)
    {

}

Tetromino::~Tetromino(){

}

void Tetromino::Draw(){

}

void Tetromino::Update(){

}

unsigned int Tetromino::GetH(){
return _hPos;
}

unsigned int Tetromino::GetV(){
return _vPos;
}

std::vector< std::vector <int> > Tetromino::GetShape(){
return _shape;
}

unsigned int Tetromino::GetHeight(){
return _shape.size();
}

unsigned int Tetromino::GetWidth(){
return _shape[0].size();
}

bool Tetromino::Sits(){
return _sits;
}
unsigned int Tetromino::GetNumber(){

}
