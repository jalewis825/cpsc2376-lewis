#pragma once

#include <iostream>
#include <vector>
#include "Engine.h"

enum class Status { ONGOING, PLAYER1_WINS, PLAYER2_WINS, DRAW };
enum class Cell { EMPTY, H_LINE, V_LINE, BOX1, BOX2 };

struct Move {
	int row;
	int col;
};

class Game {
public:
	Game(int rows = 3, int cols = 3);
	void play(int row, int col);
	Status status() const;
	void render(Engine& engine) const;
	bool handleClick(int mouseX, int mouseY);
	void reset();
	friend std::ostream& operator<<(std::ostream& os, const Game& game);

private:
	std::vector<std::vector<Cell>> grid;
	int rows;
	int cols;
	int currentPlayer;
	Status gameStatus;

	bool isValidMove(int row, int col) const;
	bool updateBoxes(int row, int col);
	bool checkWin();
};