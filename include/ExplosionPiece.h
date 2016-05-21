#ifndef EXPLOSION_PIECE_H
#define EXPLOSION_PIECE_H

#include "NonRotatableTetronimo.h"

class ExplosionPiece: public NonRotatableTetronimo{

public:
    ExplosionPiece();
    ~ExplosionPiece();
    virtual unsigned int GetHeight();
    virtual unsigned int GetWidth();
};

#endif // EXPLOSION_PIECE_H
