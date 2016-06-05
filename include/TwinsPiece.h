#ifndef TWINS_PIECE_H
#define TWINS_PIECE_H

#include "RotatableTetromino.h"

class TwinsPiece: public RotatableTetromino{

public:
    TwinsPiece();
    ~TwinsPiece();
    static Tetromino* Create(){ return new TwinsPiece; }
    virtual unsigned int GetHeight();
    virtual unsigned int GetWidth();
    virtual unsigned int GetNumber();
};

#endif // TWINS_PIECE_H

