#include <iostream>
#include "controller.h"
#include "game.h"
#include "gamemenu.h"
#include "gamedata.h"
#include "renderer.h"

int main() {
  GameMenu gamemenu;
  GameData gamedata("../data/gamedata.txt");

  while (true)
  {
    gamemenu.userSelection();
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
    gamedata.AppendPlayerScore(game.GetScore());
    gamedata.WriteScoreToGameData();
    std::cout << std::endl
              << "*************************** Leaderboard ***************************" << std::endl;
    gamedata.PrintHighScores();
  }
  return 0;
}