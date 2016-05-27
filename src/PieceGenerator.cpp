#include "PieceGenerator.h"
#include <time.h>
#include <cstdio>
#include "Tetromino.h"
#include "ExplosionPiece.h"
#include "WormPiece.h"
#include "JPiece.h"
#include "BackgroundGrid.h"
#include "ResourceManager.h"
#include "Screen.h"
#include "Node.h"
#define PCS_NR 3
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
    it -> val = 1 + rand()%PCS_NR;//numarul de tipuri de piese
    if( it -> val == 3 )
        it -> val = 7;
    it -> previous = new Node;
    it = it -> previous;
}
it -> val = 1 + rand()%PCS_NR;
if( it -> val == 3 )
        it -> val = 7;
it -> previous = NULL;
_end = it;

_position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2( - 31*5, 0 );
}

PieceGenerator::~PieceGenerator(){
Node *it = _front;
while( it -> previous )
{
    Node * temp = it;
    it = it -> previous;
    delete temp;
}

}

Tetromino * PieceGenerator::PopPiece(){
Tetromino * newPiece;
srand(time(NULL));
switch( _front->val )
{
case 1:
    {
        newPiece = new ExplosionPiece;
        break;
    }

case 2:
    {
        newPiece = new WormPiece;
        break;
    }
case 7:
    {
        newPiece = new JPiece;
        break;
    }
default:
    {
        newPiece = new WormPiece;
        break;
    }
}

Node * temp = new Node;

temp -> val = 1 + rand()%PCS_NR;
if( temp -> val == 3 )
        temp -> val = 7;
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
    char x = temp->val + 48;
    std::string lb;
    lb += "piece";
    lb += x;
    lb += "_0.png";
    Vector2 vectPos(0, -( height*31*4 + 31 ) );
    Screen::Draw( (Image*)ResourceManager::Instance()->GetResource(lb), _position + vectPos );
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
