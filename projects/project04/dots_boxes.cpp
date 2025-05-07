//AI: I was having trouble with my dots rendering at start up. I used AI to help me fix my code so I could get it to display the dots

#include "dots_boxes.h"
#include <cmath>

Game::Game(int r, int c) : rows(r), cols(c), currentPlayer(1), gameStatus(Status::ONGOING) {
	grid.resize(2 * rows + 1, std::vector<Cell>(2 * cols + 1, Cell::EMPTY));
}

bool Game::isValidMove(int row, int col) const {
	if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) {
		return false;
	}
	if ((row % 2 == 1 && col % 2 == 1) || grid[row][col] != Cell::EMPTY) {
		return false;
	}
	return true;
}

void Game::play(int row, int col, Engine& engine) {
	if (gameStatus != Status::ONGOING || !isValidMove(row, col)) {
		return;
	}

	Cell& cell = grid[row][col];
	if (row % 2 == 0) {
		cell = Cell::H_LINE;
	}
	else {
		cell = Cell::V_LINE;
	}

	engine.playSound();

	bool scored = updateBoxes(row, col, engine);
	if (!scored) {
		currentPlayer = 3 - currentPlayer;
	}

	checkWin(engine);
}

bool Game::updateBoxes(int row, int col, Engine& engine) {
	bool scored = false;
	
	int directions[4][2] = {
		{-1, 0},
		{1, 0},
		{0, -1},
		{0, 1}
	};

	for (int i = 0; i < 4; ++i) {
		int boxRow = row + directions[i][0];
		int boxCol = col + directions[i][1];

		if (boxRow <= 0 || boxRow >= grid.size() - 1 ||
			boxCol <= 0 || boxCol >= grid[0].size() - 1 ||
			boxRow % 2 == 0 || boxCol % 2 == 0) {
			continue;
		}
		

		bool top = grid[boxRow - 1][boxCol] != Cell::EMPTY;
		bool bottom = grid[boxRow + 1][boxCol] != Cell::EMPTY;
		bool left = grid[boxRow][boxCol - 1] != Cell::EMPTY;
		bool right = grid[boxRow][boxCol + 1] != Cell::EMPTY;

		if (top && bottom && left && right && grid[boxRow][boxCol] == Cell::EMPTY) {
			grid[boxRow][boxCol] = (currentPlayer == 1) ? Cell::BOX1 : Cell::BOX2;
			scored = true;

			engine.playBoxCompleteSound();
		}
	}

	return scored;
}

bool Game::checkWin(Engine& engine) {
	for (int i = 1; i < grid.size(); i += 2) {
		for (int j = 1; j < grid[0].size(); j += 2) {
			if (grid[i][j] == Cell::EMPTY) {
				return false;
			}
		}
	}

	int score1 = 0;
	int score2 = 0;
	for (auto& row : grid) {
		for (auto& cell : row) {
			if (cell == Cell::BOX1) {
				score1++;
			}
			if (cell == Cell::BOX2) {
				score2++;
			}
		}
	}

	if (score1 > score2) {
		gameStatus = Status::PLAYER1_WINS;
		engine.playVictorySound();
	}
	else if (score2 > score1) {
		gameStatus = Status::PLAYER2_WINS;
		engine.playVictorySound();
	}
	else {
		gameStatus = Status::ONGOING;
	}

	return true;
}

Status Game::status() const {
	return gameStatus;
}

void Game::render(Engine& engine) const {
	SDL_Color bgColor = {0, 0, 0, 255};
	engine.clear(bgColor);

	int cellSize = 50;

	for (int i = 0; i < grid.size(); ++i) {
		for (int j = 0; j < grid[i].size(); ++j) {
			int x = j * cellSize + cellSize / 2;
			int y = i * cellSize + cellSize / 2;

			if ((i % 2 == 0) && (j % 2 == 0)) {
				engine.drawCircle(x, y, 10, { 0, 128, 0, 255 });
				continue;
			}

			switch (grid[i][j]) {
			case Cell::H_LINE: {
				engine.drawRectangle(x, y, cellSize, 5, { 255,255,255,255 });
				break;
			}
			case Cell::V_LINE: {
				engine.drawRectangle(x, y, 5, cellSize, { 255,255,255,255 });
				break;
			}
			case Cell::BOX1: {
				engine.drawRectangle(x, y, cellSize - 10, cellSize - 10, { 0,0,255,255 });
				break;
			}
			case Cell::BOX2: {
				engine.drawRectangle(x, y, cellSize - 10, cellSize - 10, { 255,0,0,255 });
				break;
			}
			case Cell::EMPTY:
				break;
			}
		}
	}

	if (gameStatus == Status::PLAYER1_WINS) {
		engine.drawText("Player 1 Wins!", 450, 200, { 0,0,255,255 });
	}
	else if (gameStatus == Status::PLAYER2_WINS) {
		engine.drawText("Player 2 Wins!", 450, 200, { 255,0,0,255 });
	}

	//Player 1 (Blue)
	engine.drawRectangle(125, 400, 20, 20, { 0, 0, 255, 255 });
	engine.drawText("Player 1", 200, 400, { 255, 255, 255, 255 });

	//Player 2 (Red)
	engine.drawRectangle(125, 425, 20, 20, { 255, 0, 0, 255 });
	engine.drawText("Player 2", 200, 425, { 255, 255, 255, 255 });

	//Game Instructions
	engine.drawText("Click between dots to place lines.", 205, 460, { 255, 255, 255, 255 });
	engine.drawText("Complete a square to earn a point.", 205, 485, { 255, 255, 255, 255 });
	engine.drawText("Player with most squares wins!", 205, 510, { 255, 255, 255, 255 });
	engine.drawText("Press ESC to exit", 205, 535, { 255, 255, 255, 255 });

	std::string turnText = (currentPlayer == 1) ? "Player 1's Turn" : "Player 2's Turn";
	SDL_Color turnColor = (currentPlayer == 1) ? SDL_Color{ 0, 0, 255, 255 } : SDL_Color{ 255, 0, 0, 255 };
	engine.drawText(turnText.c_str(), 450, 100, turnColor);

	if (gameStatus != Status::ONGOING) {
		engine.drawText("Press R to restart", 450, 250, { 255, 255, 255, 255 });
	}

	engine.flip();

}

bool Game::handleClick(int mouseX, int mouseY, Engine& engine) {
	int cellSize = 50;
	int row = mouseY / cellSize;
	int col = mouseX / cellSize;

	if (isValidMove(row, col)) {
		play(row, col, engine);
		return true;
	}

	return false;
}

void Game::reset() {
	currentPlayer = 1;
	gameStatus = Status::ONGOING;
	for (auto& row : grid) {
		for (auto& cell : row) {
			cell = Cell::EMPTY;
		}
	}
}