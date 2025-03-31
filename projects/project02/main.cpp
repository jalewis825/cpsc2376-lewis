#include "dots_boxes.cpp"
#include "dots_boxes.h"

int main() {
    Game game;
    int row;
    int col;
    char directionInput;
    char playAgain;

    std::cout << "Welcome to Dots & Boxes!" << std::endl;
    std::cout << "When a player completes a box, they earn a point and take another turn." << std::endl;
    std::cout << "The game ends when all boxes are claimed, and the player with the most points wins!" << std::endl;

    while (game.status() == Game::Status::ONGOING) {
        std::cout << game;

        std::cout << "Player " << (game.status() == Game::Status::PLAYER_1_WINS ? "1 (X)" : "2 (O)")
            << ", enter your move (row, column, direction [T=top, B=bottom, L=left, R=right]): ";

        std::cin >> row >> col >> directionInput;

        if (row < 1 || row > Game::size || col < 1 || col > Game::size) {
            std::cout << "Invalid input. Row and column must be between 1 and" << Game::size << "Try again." << std::endl;
            continue;
        }
        Game::Direction direction;
        directionInput = std::toupper(directionInput);
        switch (directionInput) {
        case 'T':
            direction = Game::TOP;
            break;
        case 'B':
            direction = Game::BOTTOM;
            break;
        case 'L':
            direction = Game::LEFT;
            break;
        case 'R':
            direction = Game::RIGHT;
            break;
        }

        game.play(row - 1, col - 1, direction); // pushes user's input to the game & adjusts for 0-based indexing
        
        Game::Status gameStatus = game.status();
        if (gameStatus == Game::Status::PLAYER_1_WINS) {
            std::cout << "Player 1 (X) wins!" << std::endl;
        }
        else if (gameStatus == Game::Status::PLAYER_2_WINS) {
            std::cout << "Player 2 (O) wins!" << std::endl;
        }
        else if (gameStatus == Game::Status::DRAW) {
            std::cout << "It's a tie!" << std::endl;
        }
    }

    std::cout << "Play Again? (Y/N): ";
    std::cin >> playAgain;

    if (playAgain == 'Y' || playAgain == 'y') {
        game.reset();
        main(); // Restart the game by calling main() again
    }
    else {
        std::cout << "Goodbye!" << std::endl;
    }

    return 0;
}