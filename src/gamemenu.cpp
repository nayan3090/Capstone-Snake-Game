#include "gamemenu.h"
#include <iostream>
#include <string>


void GameMenu::userSelection()
{
    std::cout<< "************************* Snake Game Menu *************************" << std::endl
             << "************** Enter option 1 to 3 from the game menu *************" << std::endl
             << "*** 1. Start Game                                               ***" << std::endl
             << "*** 2. Highscores                                               ***" << std::endl
             << "*** 3. Quit                                                     ***" << std::endl
             << "*******************************************************************" << std::endl
             << "*******************************************************************" << std::endl
             <<"Your Selection: " << std::endl;
    while (std::cin >> _menuOptionSelected)
    {
        if (_menuOptionSelected == 1 || _menuOptionSelected == 2 || _menuOptionSelected == 3)
            break;

        std::cout<<"*** Please enter 1, 2 or 3 to select corresponding game menu option ***"<< std::endl;
    }        

    if (std::cin.fail())
    {
        _menuOptionSelected = 3;
        std::cerr <<"Invalid input"<<std::endl;
    }
}

int GameMenu::getSelection()
{
    return _menuOptionSelected;
}  