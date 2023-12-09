// Class definition for X_O_Board class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <bits/stdc++.h>
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

// Set the board
X_O_Board::X_O_Board()
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

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool X_O_Board::update_board(int x, int y, char mark)
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

// Display the board and the pieces on it
void X_O_Board::display_board()
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

// Returns true if there is any winner
// either X or O
bool X_O_Board::is_winner()
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

// Return true if 9 moves are done and no winner
bool X_O_Board::is_draw()
{
   return (n_moves == 9 && !is_winner());
}

bool X_O_Board::game_is_over()
{
   return n_moves >= 9;
}
