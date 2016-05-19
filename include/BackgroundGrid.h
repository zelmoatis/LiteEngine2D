#ifndef BACKGROUND_GRID_H
#define BACKGROUND_GRID_H

#include "SceneObject.h"
#include "Tetronimo.h"
#include <vector>
#include "Image.h"
#include "Vector2.h"
class BackgroundGrid: public SceneObject{
private:
    Image * _image;
    std::vector< std::vector< int > > _grid;
    Vector2 _position;
    unsigned int _pileTop;
    static BackgroundGrid* _BG_instance;
    BackgroundGrid();
    ~BackgroundGrid();
    void Lower( unsigned int v );
    void LineClear( unsigned int v );
    bool FullLine( unsigned int v );
    bool EmptyLine( unsigned int v );
    Image * _colors[7];
    //Tetronimo *_current;
public:
    unsigned int GetPileTop();
    static BackgroundGrid * Instance();
    void show_grid();
    void Draw ();
    void Update();
    Vector2 GetPosition();
    bool RoomLeft(Tetronimo * tet);
    bool RoomRight(Tetronimo * tet);
    bool RoomDown(Tetronimo * tet);
    bool RoomLeftInside(Tetronimo * tet);
    bool RoomRightInside(Tetronimo * tet);
    bool RoomDownInside(Tetronimo * tet);
    bool OverLap(Tetronimo * tet);
    void SetPiece(Tetronimo * tet);
    void Settle();
    unsigned int MinHeight(Tetronimo * tet);
};

#endif // BACKGROUND_GRID_OBJ_H


