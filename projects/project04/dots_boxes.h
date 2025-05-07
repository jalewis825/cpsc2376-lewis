#pragma once

#include <iostream>
#include <vector>
#include "Engine.h"

enum class Status { ONGOING, PLAYER1_WINS, PLAYER2_WINS };
enum class Cell { EMPTY, H_LINE, V_LINE, BOX1, BOX2 };

struct Move {
	int row;
	int col;
};

struct Dot {
	int x;
	int y;
	int radius;

	Dot(int xPos, int yPos, int rad) : x(xPos), y(yPos), radius(rad) {}
};

class Game {
public:
	Game(int rows = 3, int cols = 3);
	void play(int row, int col, Engine& engine);
	Status status() const;
	void render(Engine& engine) const;
	bool handleClick(int mouseX, int mouseY, Engine& engine);
	void reset();
	friend std::ostream& operator<<(std::ostream& os, const Game& game);

private:
	std::vector<std::vector<Cell>> grid;
	int offsetX = 50;
	int offsetY = 50;
	int dotSpacing = 80;
	int rows;
	int cols;
	int currentPlayer;
	Status gameStatus;

	bool isValidMove(int row, int col) const;
	bool updateBoxes(int row, int col, Engine& engine);
	bool checkWin(Engine& engine);
};