#ifndef EXPLOSION_PIECE_H
#define EXPLOSION_PIECE_H

#include "NonRotatableTetromino.h"

class ExplosionPiece: public NonRotatableTetromino{

public:
    ExplosionPiece();
    ~ExplosionPiece();
    virtual unsigned int GetHeight();
    virtual unsigned int GetWidth();
    virtual unsigned int GetNumber();
};

#endif // EXPLOSION_PIECE_H
