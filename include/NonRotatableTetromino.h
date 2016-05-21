#ifndef NON_ROTATABLE_TETROMINO_H
#define NON_ROTATABLE_TETROMINO_H

#include "Tetromino.h"
#include "Image.h"
#include "Vector2.h"

class NonRotatableTetromino: public Tetromino{
protected:
    Image *_image;
    Vector2 _position;//directly related to h_pos and v_pos, maybe useless
    Vector2 _destination;//directly related to grid

public:
    NonRotatableTetromino();
    virtual ~NonRotatableTetromino();
    virtual void Draw();
    virtual void Update();
};

#endif // NON_ROTATABLE_TETROMINO_H
