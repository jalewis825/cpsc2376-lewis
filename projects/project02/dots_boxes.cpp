//AI: used it to help with my operator function because I'm still trying to wrap my head around it
//also used to help with debugging issues I was facing that I couldn't figure out

#include "dots_boxes.h"

//Constructor intilizing game board, starting player, and resets score
Game::Game() : board(size, std::vector<Cell>(size)), currentPlayer(X), player1Score(0), player2Score(0) {
	board = std::vector<std::vector<Cell>>(size, std::vector<Cell>(size));
}

void Game::play(int row, int col, Direction direction) {
	if (row < 0 || row >= size || col < 0 || col >= size) {
		std::cout << "Invalid move: Out of bounds." << std::endl;
		return;
	}

	//checks to see if side has already been marked
	switch (direction) {
	case TOP:
		if (board[row][col].top) {
			std::cout << "Invalid move. Top side already marked." << std::endl;
			return;
		}
		break;
	case BOTTOM:
		if (board[row][col].bottom) {
			std::cout << "Invalid move. Bottom side already marked." << std::endl;
			return;
		}
		break;
	case LEFT:
		if (board[row][col].left) {
			std::cout << "Invalid move. Left side already marked." << std::endl;
			return;
		}
		break;
	case RIGHT:
		if (board[row][col].right) {
			std::cout << "Invalid move. Right side already marked." << std::endl;
			return;
		}
		break;
	}

	//marks the appropriate side of the cell
	switch (direction) {
	case TOP:
		board[row][col].top = true;
		if (row > 0) {
			board[row - 1][col].bottom = true;
		}
		break;
	case BOTTOM:
		board[row][col].bottom = true;
		if (row < size - 1) {
			board[row + 1][col].top = true;
		}
		break;
	case LEFT:
		board[row][col].left = true;
		if (col > 0) {
			board[row][col - 1].right = true;
		}
		break;
	case RIGHT:
		board[row][col].right = true;
		if (col < size - 1) {
			board[row][col + 1].left = true;
		}
		break;
	}

	//awards extra turn if player completes a box
	bool extraTurn = completeBox(row, col);

	checkAdjacentBoxes(row, col, direction, extraTurn);

	//switches players if no extra turn rewarded
	if (!extraTurn) {
		currentPlayer = (currentPlayer == X) ? O : X;
	}
}

bool Game::completeBox(int row, int col) {
	if (board[row][col].top && board[row][col].bottom
		&& board[row][col].left && board[row][col].right) {

		if (board[row][col].owner == NONE) {
			board[row][col].owner = currentPlayer;
		}
		if (currentPlayer == X) {
			player1Score++;
		}
		else if (currentPlayer == O) {
			player2Score++;
		}
		return true;
	}
	return false;
}

void Game::checkAdjacentBoxes(int row, int col, Direction direction, bool& extraTurn) {
	switch (direction) {
	case Direction::TOP:
		if (row > 0) {
			extraTurn |= completeBox(row - 1, col);//top neighbor
		}
		break;
	case Direction::BOTTOM:
		if (row < size - 1) {
			extraTurn |= completeBox(row + 1, col);  // Bottom neighbor
		}
		break;
	case Direction::LEFT:
		if (col > 0) {
			extraTurn |= completeBox(row, col - 1);  // Left neighbor
		}
		break;
	case Direction::RIGHT:
		if (col < size - 1) {
			extraTurn |= completeBox(row, col + 1);  // Right neighbor
		}
		break;
	}
}

Game::Status Game::status() const {
	int totalBoxes = size * size;
	int totalMoves = player1Score + player2Score;

	if (totalMoves == totalBoxes) {
		return (player1Score > player2Score) ? PLAYER_1_WINS :
			(player2Score > player1Score) ? PLAYER_2_WINS : DRAW;
	}
	return Status::ONGOING; //not all boxes are claimed & games still ongoing
}

std::ostream& operator<<(std::ostream& os, const Game& game) {

	//print column numbers
	os << "    ";
	for (int col = 1; col <= Game::size; col++) {
		os << col << "   ";
	}
	os << std::endl;

	//print each row
	for (int row = 0; row < Game::size; row++) {
		//print dots & horizontal lines when move is made for that side
		os << "  ";
		for (int col = 0; col < Game::size; col++) {
			os << "." << (game.board[row][col].top ? "---" : "   ");
		}
		os << "." << std::endl;

		//box owner & vertical lines
		os << row + 1 << " ";
		for (int col = 0; col < Game::size; col++) {
			os << (game.board[row][col].left ? "| " : "  "); //if left side is true display | other wise show nothing
			if (game.board[row][col].owner == Game::Player::X) {
				os << "X ";
			}
			else if (game.board[row][col].owner == Game::Player::O) {
				os << "O ";
			}
			else {
				os << "  "; //empty box til owned
			}

		}

		if (game.board[row][Game::size - 1].right) {
			os << "|";
		}

		os << std::endl;
	}

	//print bottom boarder
	os << "  ";
	for (int col = 0; col < Game::size; col++) {
		os << "." << (game.board[Game::size - 1][col].bottom ? "___" : "   ");
	}
	os << "." << std::endl;
	os << std::endl;

	return os;
}

void Game::reset() {
	//resets the board & each cell
	board = std::vector<std::vector<Cell>>(size, std::vector<Cell>(size));

	//resets each player score
	player1Score = 0;
	player2Score = 0;

	//set starting player to X
	currentPlayer = Player::X;
}