#ifndef BACKGROUND_GRID_H
#define BACKGROUND_GRID_H

#include "SceneObject.h"
#include "Tetromino.h"
#include <vector>
#include "Image.h"
#include "Vector2.h"
class BackgroundGrid: public SceneObject{
private:
    std::vector< std::vector< int > > _grid;
    Vector2 _position;
    Image * _image;
    unsigned int _pileTop;
    unsigned int _pieces;
    unsigned int _clearedLines;
    unsigned int _pieceTurn;
    static BackgroundGrid* _BG_instance;
    BackgroundGrid();
    BackgroundGrid(const BackgroundGrid&);
    BackgroundGrid& operator=(const BackgroundGrid&);
    ~BackgroundGrid();
    void Lower( unsigned int v );
    void LineClear( unsigned int v );
    bool FullLine( unsigned int v );
    bool EmptyLine( unsigned int v );
public:
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
    bool ReachedTop();
    unsigned int MinHeight(Tetromino * tet);
    unsigned int GetClearedLines();
    unsigned int GetPieces();
    unsigned int GetTurn();
    void Reset();
};

#endif // BACKGROUND_GRID_OBJ_H


