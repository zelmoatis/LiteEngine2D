#ifndef NON_ROTATABLE_TETRONIMO_H
#define NON_ROTATABLE_TETRONIMO_H

#include "Tetronimo.h"
#include "Image.h"
#include "Vector2.h"

class NonRotatableTetronimo: public Tetronimo{
protected:
    Image *_image;
    Vector2 _position;//directly related to h_pos and v_pos, maybe useless
    Vector2 _destination;//directly related to grid

public:
    NonRotatableTetronimo();
    virtual ~NonRotatableTetronimo();
    virtual void Draw();
    virtual void Update();
};

#endif // NON_ROTATABLE_TETRONIMO_H
