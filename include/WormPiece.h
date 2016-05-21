#ifndef WORM_PIECE_H
#define WORM_PIECE_H

#include "RotatableTetronimo.h"

class WormPiece: public RotatableTetronimo{

public:
    WormPiece();
    ~WormPiece();
    virtual unsigned int GetHeight();
    virtual unsigned int GetWidth();
    void RotateLeft();
    void RotateRight();
};

#endif // WORM_PIECE_H
