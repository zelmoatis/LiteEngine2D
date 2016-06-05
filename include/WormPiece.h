#ifndef WORM_PIECE_H
#define WORM_PIECE_H

#include "RotatableTetromino.h"

class WormPiece: public RotatableTetromino{

public:
    WormPiece();
    ~WormPiece();
    static Tetromino* Create(){ return new WormPiece; }
    virtual unsigned int GetHeight();
    virtual unsigned int GetWidth();
    virtual unsigned int GetNumber();
};

#endif // WORM_PIECE_H
