#pragma once
#include "Game.h"
#include <iostream>

class TicTacToe : public Game // tic tac toe inherits from Game class
{
private:
    char m_Board[9]; // Array of 9 characters to represent the board
    char m_CurrentPlayer; // Character to represent the current player

public:
    // Constructor

    TicTacToe() : m_CurrentPlayer('X') // Initialize the current player to X
    {
        for (int i = 0; i < 9; ++i) {
            m_Board[i] = '1' + i; // Initialize board with characters '1' to '9'
        }
    }

	// Destructor (default by compiler)

	~TicTacToe() { }

	// Member functions to be overridden in the cpp file 

    void Display() const override;    // Display the board
    bool IsGameOver() const override; // Check if the game is over
    void TakeTurn() override;         // Take the player's turn
};
