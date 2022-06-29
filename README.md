# CPPND: Capstone Snake Game

This repository contains the code for the Capstone project which is a part of the Udacity C++ Nanodegree.

The project code in this repository is based off of the starter code provided in [CppND-Capstone-Snake-Game](https://github.com/udacity/CppND-Capstone-Snake-Game) github repository

<img src="snake_game.gif"/>

## Added Features
* The player is presented with a `GameMenu` to select amongst the options available in the menu. The game menu is displayed in the terminal as shown here:
![Game Menu](images/gamemenu.png)
  * Selecting the first option - `1. Start Game`, launches a new game
  * Second option - `2. Highscores` displays the leaderboard. It prints out the top ten scores ever achieved by the players who played this game
  ![Leaderboard](images/leaderboard.png)
  * The last option - `3. Quit`, allows the player to successfully terminate the game
* To make the game more exciting and increasing the challenge periodically throughout the game playing time, `Posion` is added to the game. The poison blocks are added randomly one by one everytime the score increases by 5. The snake dies after eating the poison block and the game is over.
* Game window automatically terminates when the snake dies as the game is over. 
* At the end of the game, the player's score is displayed in the terminal and further the player's score is compared with the top ten scores on the leaderboard. Based on:
  * If the player's score is less than the minimum score in the leaderboard, the game shows the leaderboard to the player and takes them back to the game menu.
  * If the player's score is greater than the minimum score in the leaderboard, the game asks the player to provide their name and subsequently stores their name and score in the leaderboard and takes out the last leaderboard entry to ensure that the leaderboard stores only the top ten scores of all time. The game displays the new leaderboard and then takes the player back to the game menu.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## Overview of Code Structure

The Snake game code consists of six main classes: `Game`, `Snake`, `Controller`, `Renderer`, `GameMenu` and `GameData`. The image below shows how the code functions:

![Code Structure](images/codestructure.png)

## 