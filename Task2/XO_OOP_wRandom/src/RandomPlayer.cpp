// Class definition for XO_RandomPlayer class
// Which is a computer player playing randomly
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

// Set player symbol and name as Random Computer Player
RandomPlayer::RandomPlayer(char symbol, int dimension) : Player(symbol)
{
    srand(static_cast<unsigned>(time(NULL)));
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move
void RandomPlayer::get_move(int &x, int &y)
{
    x = (int)(rand() / (RAND_MAX + 1.0) * dimension);
    y = (int)(rand() / (RAND_MAX + 1.0) * dimension);
}

Pyramic_RandomPlayer::Pyramic_RandomPlayer(char symbol, int dimension) : RandomPlayer(symbol, dimension) {}

void Pyramic_RandomPlayer::Pyramic_get_move(int &x, int &y)
{
    x = rand() % dimension;
    y = rand() % (2 * x + 1);
}
