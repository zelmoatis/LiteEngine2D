#include "UpcomingList.h"
#include <time.h>
#include <cstdio>
#include "Tetromino.h"
#include "PieceGenerator.h"
#include "BackgroundGrid.h"
#include "ResourceManager.h"
#include "Screen.h"
#include "Node.h"


UpcomingList::UpcomingList(){

srand(time(NULL));
_max = 4;
_front = new Node;
Node * it = _front;
for( unsigned int i = 0; i < _max-1; i ++ )
{
    it -> val = 1 + rand()%PieceGenerator::Instance()->PieceTypes();
    it -> previous = new Node;
    it = it -> previous;
}
it -> val = 1 + rand()%PieceGenerator::Instance()->PieceTypes();

it -> previous = NULL;
_end = it;

_position = Vector2(BackgroundGrid::Instance()->GetPosition()) + Vector2( - 31*5, -93 );

}

UpcomingList::~UpcomingList(){
    Clear();
}

Tetromino * UpcomingList::PopPiece(){
Tetromino * newPiece;
srand(time(NULL));

newPiece = PieceGenerator::Instance()->NumberGetPiece(_front->val);
Node * temp = new Node;

temp -> val = 1 + rand()%PieceGenerator::Instance()->PieceTypes();
_end -> previous = temp;
_end = temp;
_end -> previous = NULL;

temp = _front;
_front = _front -> previous;

delete temp;
return newPiece;
}

void UpcomingList::Draw(){
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

void UpcomingList::Update(){

}

void UpcomingList::Clear(){

Node *it = _front;
while( it -> previous )
{
    Node * temp = it;
    it = it -> previous;
    delete temp;
}

}

void UpcomingList::Reset(){

Clear();

srand(time(NULL));
_front = new Node;
Node * it = _front;
for( unsigned int i = 0; i < _max-1; i ++ )
{
    it -> val = 1 + rand()%PieceGenerator::Instance()->PieceTypes();//numarul de tipuri de piese
    it -> previous = new Node;
    it = it -> previous;
}
it -> val = 1 + rand()%PieceGenerator::Instance()->PieceTypes();

it -> previous = NULL;
_end = it;

}
