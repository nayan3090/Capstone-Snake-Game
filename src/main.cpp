#include <iostream>
#include "controller.h"
#include "game.h"
#include "gamemenu.h"
#include "gamedata.h"
#include "renderer.h"

int main() {
  // New features:
  // (1) Creates GameMenu in the terminal to take input from the player to decide what to do next in the game 
  // (2) Retrieves GameData to display 'Highscores' if asked by the player or at the end of the game, decide based on the player's score if their name would be up there on the Leaderboard
  GameMenu gamemenu;
  GameData gamedata("../data/gamedata.txt");

  while (true)
  {
    // Loops, Functions, I/O Criteria: Processes player's input
    gamemenu.userSelection();
    // Loops, Functions, I/O Criteria: Example to demonstrate the usage of control structure
    // Used 'switch case' to manipulate the output of the program based on player's input
    switch (gamemenu.getSelection())
    {
      case 1:
        break;

      case 2:
        gamedata.PrintHighScores();
        continue;

      case 3:
        std::cout << "Game has terminated successfully!" << std::endl;
        return 0;
      
      default:
        std::cerr << "Invalid input" << std::endl
                  <<"Game has terminated successfully!" << std::endl;
        return 0;
    }

    std::cout << "*******************************************************************" << std::endl
              << "***                         STARTING THE GAME                   ***" << std::endl
              << "*******************************************************************" << std::endl;
    std::cout << std::endl;

    constexpr std::size_t kFramesPerSecond{60};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
    constexpr std::size_t kScreenWidth{640};
    constexpr std::size_t kScreenHeight{640};
    constexpr std::size_t kGridWidth{32};
    constexpr std::size_t kGridHeight{32};


    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    Game game(kGridWidth, kGridHeight);
    game.Run(controller, renderer, kMsPerFrame);
    std::cout << "Game has terminated successfully!\n";
    std::cout << "Your Score: " << game.GetScore() << "\n";
    // Loops, Functions, I/O Criteria: Processes player's input
    gamedata.AppendPlayerScore(game.GetScore());
    gamedata.WriteScoreToGameData();
    std::cout << std::endl
              << "*************************** Leaderboard ***************************" << std::endl;
    gamedata.PrintHighScores();
  }
  return 0;
}