#include "gamedata.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

/* GameData Constructor */
GameData::GameData(std::string name) : _fileName(name)
{
    std::ifstream input(name);
    std::string player;
    int score;
    if (!input)
    {
        std::ofstream(name, std::fstream::out);
        return;
    }

    while (input >> player)
    {
        input >> score;
        _playerScore.insert(std::pair<int, std::string>(score, player));
    }
}

// Loops, Functions, I/O Criteria: Example to demonstrate the usage of function
void GameData::PrintHighScores()
{
    if (_playerScore.empty()){
        std::cout << "No game record exists!"<<std::endl;
        std::cout << std::endl;
        return;
    }

    std::cout << std::setw(6) << "Rank" << "\t|" 
              << std::setw(12) << " PlayerName" << "\t|" 
              << std::setw(6) << "Score" << "\t|"
              << std::endl;

    std::multimap<int,std::string>::iterator map_data = _playerScore.begin();
    int len = _playerScore.size() > 10 ? 10 : _playerScore.size();
    int i = 1;
    for (map_data; map_data != _playerScore.end() && i <= len; ++map_data)
    {
        std::cout << std::setw(6) << std::to_string(i) << "\t|"
                  << std::setw(12) << map_data->second << "\t|"
                  << std::setw(6) << map_data->first << "\t|"
                  << std::endl;
        i++;
    } 

    std::cout<<std::endl;
}

void GameData::AppendPlayerScore(int score)
{
    if (_playerScore.size() <= 10)
    {
        std::string player = AddPlayerName();
        _playerScore.insert(std::pair<int, std::string>(score, player));
    }
    else if (_playerScore.size() > 10 && score > _playerScore.rbegin()->first)
    {
        _playerScore.erase(_playerScore.rbegin()->first);
        std::string player = AddPlayerName();
        _playerScore.insert(std::pair<int, std::string>(score, player));
    }
    
}

std::string GameData::AddPlayerName()
{
    std::string player;
    std::cout <<"Please Type Your Name >>> " << std::endl;
    std::cin >> player;
    return player;
}

void GameData::WriteScoreToGameData()
{
    std::ofstream output(_fileName, std::ofstream::out);
    std::multimap<int,std::string>::iterator map_data;
    for (map_data = _playerScore.begin(); map_data != _playerScore.end(); map_data++)
    {
        output << map_data->second << "\t" << map_data->first << std::endl;
    }
}