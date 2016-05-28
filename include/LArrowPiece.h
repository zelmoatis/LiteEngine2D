#ifndef LARROW_PIECE_H
#define LARROW_PIECE_H

#include "RotatableTetromino.h"

class LArrowPiece: public RotatableTetromino{

public:
    LArrowPiece();
    ~LArrowPiece();
    virtual unsigned int GetHeight();
    virtual unsigned int GetWidth();
};
#endif // LARROW_PIECE_H

