#include "dots_boxes.h"
#include <cmath>

Game::Game(int r, int c) : rows(r), cols(c), currentPlayer(1), gameStatus(Status::ONGOING) {
	grid.resize(2 * rows + 1, std::vector<Cell>(2 * cols + 1, Cell::EMPTY));
}

bool Game::isValidMove(int row, int col) const {
	if (row < 0 || col < 0 >= grid.size() || col >= grid[0].size()) {
		return false;
	}
	if ((row % 2 == 1 && col % 2 == 1) || grid[row][col] != Cell::EMPTY) {
		return false;
	}
	return true;
}

void Game::play(int row, int col) {
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

	bool scored = updateBoxes(row, col);
	if (!scored) {
		currentPlayer = 3 - currentPlayer;
	}

	checkWin();
}

bool Game::updateBoxes(int row, int col) {
	bool scored = false;
	int dRow[] = { -1, 0 };
	int dCol[] = { 0, -1 };

	for (int i = 0; i < 2; ++i) {
		int r = row + dRow[i] * 2;
		int c = col + dCol[i] * 2;
		int boxRow = row + dRow[i];
		int boxCol = col + dCol[i];
		if (boxRow <= 0 || boxRow >= grid.size() - 1 || boxCol <= 0 || boxCol >= grid[0].size() - 1) {
			continue;
		}

		bool top = grid[boxRow - 1][boxCol] != Cell::EMPTY;
		bool bottom = grid[boxRow + 1][boxCol] != Cell::EMPTY;
		bool left = grid[boxRow][boxCol - 1] != Cell::EMPTY;
		bool right = grid[boxRow][boxCol + 1] != Cell::EMPTY;

		if (top && bottom && left && right && grid[boxRow][boxCol] == Cell::EMPTY) {
			grid[boxRow][boxCol] = (currentPlayer == 1) ? Cell::BOX1 : Cell::BOX2;
			scored = true;
		}
	}

	return scored;
}

bool Game::checkWin() {
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
	}
	else if (score2 > score1) {
		gameStatus = Status::PLAYER2_WINS;
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
	int cellSize = 50;
	SDL_Color bgColor = { 0, 0, 0, 255 };
	engine.clear(bgColor);

	for (int i = 0; i < grid.size(); ++i) {
		for (int j = 0; j < grid[i].size(); ++j) {
			int x = j * cellSize + cellSize / 2;
			int y = i * cellSize + cellSize / 2;

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
			case Cell::EMPTY: {
				if (i % 2 == 0 && j % 2 == 0) {
					engine.drawCircle(x, y, 5, { 255,255,0,255 });
				}
				break;
			}
			}
		}
	}

	if (gameStatus == Status::PLAYER1_WINS) {
		engine.drawText("Player 1 Wins!", 350, 30, { 255,255,255,255 });
	}
	else if (gameStatus == Status::PLAYER2_WINS) {
		engine.drawText("Player 2 Wins!", 350, 30, { 255,255,255,255 });
	}

	engine.flip();

}

bool Game::handleClick(int mouseX, int mouseY) {
	int cellSize = 50;
	int row = mouseY / cellSize;
	int col = mouseX / cellSize;

	if (isValidMove(row, col)) {
		play(row, col);
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