#ifndef L_PIECE_H
#define L_PIECE_H

#include "RotatableTetromino.h"

class LPiece: public RotatableTetromino{

public:
    LPiece();
    ~LPiece();
    virtual unsigned int GetHeight();
    virtual unsigned int GetWidth();
};

#endif // L_PIECE_H

