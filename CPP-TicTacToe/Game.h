
// This file is complete, and should not be modified!

#pragma once

class Game
{

public:

	Game() { } //constructor
	Game(const Game&) = delete; //copy constructor
	virtual ~Game() { } //destructor

	Game& operator=(const Game&) = delete; //destructor


	// Methods to be implemented by derived class

	virtual bool IsGameOver() const = 0;

	virtual void TakeTurn() = 0;

	virtual void Display() const = 0;

};

