#ifndef WORM_PIECE_H
#define WORM_PIECE_H

#include "RotatableTetromino.h"

class WormPiece: public RotatableTetromino{

public:
    WormPiece();
    ~WormPiece();
    virtual unsigned int GetHeight();
    virtual unsigned int GetWidth();
};

#endif // WORM_PIECE_H
