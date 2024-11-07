#pragma once
#include "TicTacToe.h"
#include <iostream>
void TicTacToe::Display() const
{
	//display the board
	std::cout << " " << m_Board[0] << " | " << m_Board[1] << " | " << m_Board[2] << std::endl;
	std::cout << "---|---|---" << std::endl;
	std::cout << " " << m_Board[3] << " | " << m_Board[4] << " | " << m_Board[5] << std::endl;
	std::cout << "---|---|---" << std::endl;
	std::cout << " " << m_Board[6] << " | " << m_Board[7] << " | " << m_Board[8] << std::endl;
}

//attempt 1: using if statements and 1d array
//bool TicTacToe::IsGameOver() const {
//	//check if the game is over
//	if (m_Board[0] == m_Board[1] && m_Board[1] == m_Board[2]) return true;
//	if (m_Board[3] == m_Board[4] && m_Board[4] == m_Board[5]) return true;
//	if (m_Board[6] == m_Board[7] && m_Board[7] == m_Board[8]) return true;
//	if (m_Board[0] == m_Board[3] && m_Board[3] == m_Board[6]) return true;
//	if (m_Board[1] == m_Board[4] && m_Board[4] == m_Board[7]) return true;
//	if (m_Board[2] == m_Board[5] && m_Board[5] == m_Board[8]) return true;
//	if (m_Board[0] == m_Board[4] && m_Board[4] == m_Board[8]) return true;
//	if (m_Board[2] == m_Board[4] && m_Board[4] == m_Board[6]) return true;
//	elseif(m_Board[0] != '1' && m_Board[1] != '2' && m_Board[2] != '3' 
//				&& m_Board[3] != '4' && m_Board[4] != '5' && m_Board[5] != '6' 
//					&& m_Board[6] != '7' && m_Board[7] != '8' && m_Board[8] != '9') 
// {
//		std::cout << "The game is a draw!" << std::endl;
//		return true;
// }

//	return false;
//}

//try 2: using a 2d array

bool TicTacToe::IsGameOver() const {
	int winningCombinations[8][3] = {
		{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, //rows
		{0, 3, 6}, {1, 4, 7}, {2, 5, 8}, //columns
		{0, 4, 8}, {2, 4, 6} //diagonals
	};
	for (int i = 0; i < 8; i++)
	{
		int a = winningCombinations[i][0];
		int b = winningCombinations[i][1];
		int c = winningCombinations[i][2];

		if (m_Board[a] == m_Board[b] && m_Board[b] == m_Board[c])
		{
			std::cout << "Player " << m_CurrentPlayer << " wins!" << std::endl;
			return true;
		} 
		//if all array locations have been assigned a value and no winner has been declared, the game is a draw
		else if (m_Board[0] != '1' && m_Board[1] != '2' && m_Board[2] != '3' && m_Board[3] != '4' && m_Board[4] != '5' && m_Board[5] != '6' && m_Board[6] != '7' && m_Board[7] != '8' && m_Board[8] != '9')
		{
			std::cout << "The game is a draw!" << std::endl;
			return true;
		}
	}
	return false;
	};

void TicTacToe::TakeTurn() {

	if (m_CurrentPlayer == 'X') {
		m_CurrentPlayer = 'O';
	}
	else {
		m_CurrentPlayer = 'X';
	}

	//take the turn of the player

	int move = 0;

	while (true) {
		std::cout << "Player " << m_CurrentPlayer << ", enter your move (1-9): ";
		std::cin >> move;

		if (move >= 1 && move <= 9 && m_Board[move - 1] != 'X' && m_Board[move - 1] != 'O') {
			m_Board[move - 1] = m_CurrentPlayer;
			break;
		}
		else {
			std::cout << "Invalid move. Please try again." << std::endl;
		}
	}

}