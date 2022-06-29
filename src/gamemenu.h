#ifndef GAMEMENU_H
#define GAMEMENU_H

class GameMenu{
public:
    // Class constructor
    GameMenu() {};

    void userSelection();
    int getSelection();

private:
    int _menuOptionSelected;
};

#endif