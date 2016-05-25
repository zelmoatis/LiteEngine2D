#include "PieceGenerator.h"
#include <time.h>
#include <cstdio>
#include "Tetromino.h"
#include "ExplosionPiece.h"
#include "WormPiece.h"
#include "BackgroundGrid.h"
#include "Resources.h"
#include "Screen.h"
#include "Node.h"
#define PCS_NR 2
PieceGenerator* PieceGenerator:: _PGEN_instance = 0;

PieceGenerator* PieceGenerator::Instance(){
    if(!_PGEN_instance)
    {
        _PGEN_instance = new PieceGenerator;
    }
    return _PGEN_instance;
}



PieceGenerator::PieceGenerator(){
srand(time(NULL));
_max = 4;
_front = new Node;
Node * it = _front;
for( unsigned int i = 0; i < _max-1; i ++ )
{
    it -> val = rand()%PCS_NR;//numarul de tipuri de piese
    it -> previous = new Node;
    it = it -> previous;
}
it -> val = rand()%PCS_NR;
it -> previous = NULL;
_end = it;

_position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2( - 31*5, 0 );
_images[0] = Resources::LoadImage("Assets/Images/badris/1piece.png");
_images[1] = Resources::LoadImage("Assets/Images/badris/2piece_0.png");
}

PieceGenerator::~PieceGenerator(){
Node *it = _front;
while( it -> previous )
{
    Node * temp = it;
    it = it -> previous;
    delete temp;
}
for( int i = 0; i < 2; i ++ )
{
    delete _images[i];
}
}

Tetromino * PieceGenerator::PopPiece(){
Tetromino * newPiece;
srand(time(NULL));
switch( _front->val )
{
case 0:
    {
        newPiece = new ExplosionPiece;
        break;
    }

case 1:
    {
        newPiece = new WormPiece;
        break;
    }
default:
    {
        newPiece = new WormPiece;
        break;
    }
}

Node * temp = new Node;

temp -> val = rand()%PCS_NR;
_end -> previous = temp;
_end = temp;
_end -> previous = NULL;

temp = _front;
_front = _front -> previous;
delete temp;

return newPiece;
}

void PieceGenerator::Draw(){
int height = 0;
Node * temp = _front;
while( temp )
{
    Vector2 vectPos(0, -( height*31*4+31*4-(int)_images[temp->val]->GetHeight() + 31 ) );
    Screen::Draw(_images[temp->val], _position + vectPos );
    height++;
    temp = temp -> previous;
}
}

void PieceGenerator::Update(){

}

void PieceGenerator::show_list(){
Node * it = _front;
std::cout<<"Lista:\n";
for( unsigned int i = 0; i < _max-1; i ++ )
{
    std::cout<<it->val<<"\n";
    it = it -> previous;
}
}
