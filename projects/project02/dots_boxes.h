//AI: Used for a few organization helpers but mainly just reconfigured my code from previous project to be object oriented
#pragma once

#include <iostream>
#include <vector>

enum Player { NONE, X, O };

class Game {
public:
	enum Direction { TOP, BOTTOM, LEFT, RIGHT };
	enum Status { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };

	static const int size = 3;

	Game();
	void play(int row, int col, Direction direction);
	Status status() const;
	void reset();

	friend std::ostream& operator<<(std::ostream& os, const Game& game);

private:
	struct Cell {
		bool top = false;
		bool bottom = false;
		bool left = false;
		bool right = false;
		Player owner = Player::NONE;
	};

	std::vector<std::vector<Cell>> board;
	Player currentPlayer;
	int player1Score;
	int player2Score;

	bool completeBox(int row, int col);
	void checkAdjacentBoxes(int row, int col, Direction direction, bool& extraTurn);
};