#ifndef UPCOMINGLIST_H
#define UPCOMINGLIST_H

#include "SceneObject.h"
#include "Tetromino.h"
#include "Vector2.h"
#include "Node.h"
#include <map>

class UpcomingList:public SceneObject{
private:
    UpcomingList();
    UpcomingList(const UpcomingList&);
    UpcomingList &operator=(const UpcomingList&);
    void Clear();
    Node *_front;
    Node *_end;
    Vector2 _position;
    unsigned int _max;
public:
    static UpcomingList *Instance()
    {
        static UpcomingList instance;
        return &instance;
    }
    ~UpcomingList();
    Tetromino* PopPiece();
    void Draw();
    void Update();
    void Reset();
};


#endif // UPCOMINGLIST_H
