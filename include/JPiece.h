#ifndef J_PIECE_H
#define J_PIECE_H

#include "RotatableTetromino.h"

class JPiece: public RotatableTetromino{

public:
    JPiece();
    ~JPiece();
    virtual unsigned int GetHeight();
    virtual unsigned int GetWidth();
    virtual unsigned int GetNumber();
};

#endif // J_PIECE_H
