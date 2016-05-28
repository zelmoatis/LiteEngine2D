#ifndef LARROW_PIECE_H
#define LARROW_PIECE_H

#include "RotatableTetromino.h"

class LArrowPiece: public RotatableTetromino{

public:
    LArrowPiece();
    ~LArrowPiece();
    virtual unsigned int GetHeight();
    virtual unsigned int GetWidth();
    virtual unsigned int GetNumber();
};
#endif // LARROW_PIECE_H

