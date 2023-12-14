#include <bits/stdc++.h>
using namespace std;

#include "../include/BoardGame_Classes.hpp"
int main()
{
    int choice;
    Player *players[2];
    players[0] = new Player(1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player(2, 'o');
    else
        // Player pointer points to child
        players[1] = new RandomPlayer('o', 3);

    GameManager x_o_game(new pyramic_xo_board(), players);
    x_o_game.run();
    system("pause");
}