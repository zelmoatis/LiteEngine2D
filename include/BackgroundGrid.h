#ifndef BACKGROUND_GRID_H
#define BACKGROUND_GRID_H

#include "SceneObject.h"
#include "Tetromino.h"
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
public:
    unsigned int GetPileTop();
    static BackgroundGrid * Instance();
    void show_grid();
    void Draw ();
    void Update();
    Vector2 GetPosition();
    bool RoomLeft(Tetromino * tet);
    bool RoomRight(Tetromino * tet);
    bool RoomDown(Tetromino * tet);
    bool OverLap( std::vector< std::vector <int> >, unsigned int h, unsigned int v );
    void SetPiece(Tetromino * tet);
    void Settle();
    unsigned int MinHeight(Tetromino * tet);
};

#endif // BACKGROUND_GRID_OBJ_H


