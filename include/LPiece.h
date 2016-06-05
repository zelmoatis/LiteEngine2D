#ifndef L_PIECE_H
#define L_PIECE_H

#include "RotatableTetromino.h"

class LPiece: public RotatableTetromino{

public:
    LPiece();
    ~LPiece();
    static Tetromino* Create(){ return new LPiece; }
    virtual unsigned int GetHeight();
    virtual unsigned int GetWidth();
    virtual unsigned int GetNumber();
};

#endif // L_PIECE_H

