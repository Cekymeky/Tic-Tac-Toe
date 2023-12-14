#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "bits/stdc++.h"
#include <vector>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

pyramic_xo_board::pyramic_xo_board()
{
    n_rows = 3;
    n_cols = 5;
    board = vector<vector<char>>(n_rows);

    for (int i = 1; i < n_rows + 1; ++i)
    {
        vector<char> v(2 * i - 1, 0);
        board[i - 1] = v;
    }
}

void pyramic_xo_board::display_board()
{
    for (int i : {0, 1, 2})
    {
        for (int k = 0; k < 8.25 * (n_rows - i); ++k)
            cout << " ";
        cout << "| ";
        for (int j = 0; j < board[i].size(); ++j)
        {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << "| ";
        }
        cout << "\n\n";
    }
    cout << "--------------------------------------------------------------\n";
}

bool pyramic_xo_board::update_board(int x, int y, char mark)
{
    // Only update if move is valid
    if (!(x < 0 || x > 2 || y < 0 || y > 2 * x + 1) && (board[x][y] == 0))
    {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

bool pyramic_xo_board::is_winner()
{
    char diag_win[2];

    //  diagonal wins
    diag_win[0] = (board[0][0] == board[1][2]) && (board[1][2] == board[2][4]) && (board[2][4] != 0);
    diag_win[1] = (board[2][0] == board[1][0]) && (board[1][0] == board[0][0]) && (board[0][0] != 0);

    if (diag_win[0] || diag_win[1])
    {
        return true;
    }

    //  horizontal wins
    char hor_win[4];
    hor_win[0] = (board[1][0] == board[1][1]) && (board[1][1] == board[1][2]) && (board[1][2] != 0);
    hor_win[1] = (board[2][0] == board[2][1]) && (board[2][1] == board[2][2]) && (board[2][2] != 0);
    hor_win[2] = (board[2][1] == board[2][2]) && (board[2][2] == board[2][3]) && (board[2][3] != 0);
    hor_win[3] = (board[2][2] == board[2][3]) && (board[2][3] == board[2][4]) && (board[2][4] != 0);

    if (hor_win[0] || hor_win[1] || hor_win[2] || hor_win[3])
    {
        return true;
    }
    //  vertical win

    if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[2][2] != 0))
    {
        return true;
    }

    return false;
}

bool pyramic_xo_board::is_draw()
{
    return (n_moves == 9 && !is_winner());
}

bool pyramic_xo_board::game_is_over()
{
    return n_moves >= 9;
}