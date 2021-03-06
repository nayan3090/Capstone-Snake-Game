#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <string>
#include <map>

class GameData {
public:
    GameData(std::string name);
    ~GameData() {};

    void PrintHighScores();
    void AppendPlayerScore(int score);
    void WriteScoreToGameData();


private:
    std::string _fileName;
    std::multimap<int, std::string, std::greater<int>> _playerScore;

    std::string AddPlayerName();
};

#endif