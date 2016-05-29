#ifndef LAYOUTMANAGER_H
#define LAYOUTMANAGER_H

#include "Vector2.h"
#include <vector>
#include "ClickableButton.h"

class LayoutManager{
private:
    //needs more attributes for buttons arrangement
    std::vector< ClickableButton * > _buttons;
    Vector2 _position;
public:
    LayoutManager();
    LayoutManager( const Vector2& pos );
    ~LayoutManager();
    void Update();
    void Display();//draws all the buttons
    void AddButton( ClickableButton * button );
    std::string GetActivatedButton();//returns name of pressed button
    void ResetButtons();
};

#endif // LAYOUTMANAGER_H
