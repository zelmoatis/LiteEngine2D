#ifndef RARROW_PIECE_H
#define RARROW_PIECE_H

#include "RotatableTetromino.h"

class RArrowPiece: public RotatableTetromino{

public:
    RArrowPiece();
    ~RArrowPiece();
    virtual unsigned int GetHeight();
    virtual unsigned int GetWidth();
    virtual unsigned int GetNumber();
};
#endif // RARROW_PIECE_H
