//AI: I was having some logic errors with my checking user input for direction that I used AI to help me solve
#include "dots_boxes.h"
#include <limits>

int main() {
    Game game; 
    char playAgain = 'Y';

    std::cout << "Welcome to Dots & Boxes!" << std::endl;
    std::cout << "When a player completes a box, they earn a point and take another turn." << std::endl;
    std::cout << "The game ends when all boxes are claimed, and the player with the most points wins!" << std::endl;

    while (playAgain == 'Y' || playAgain == 'y') {
        while (game.status() == Game::Status::ONGOING) {
            std::cout << game;

            int row;
            int col;
            char directionInput;

            std::cout << "Player " << (game.getCurrentPlayer() == Game::Player::X ? "1 (X)" : "2 (O)")
                << ", enter your move (row, column, direction [T=top, B=bottom, L=left, R=right]): ";

            std::cin >> row >> col >> directionInput;

            if (std::cin.fail() || row < 1 || row > Game::size || col < 1 || col > Game::size) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Row and column must be between 1 and " << Game::size << ". Try again." << std::endl;
                continue;
            }

            directionInput = std::toupper(directionInput);
            Game::Direction direction;
            bool validDirection = true;

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
            default:
                validDirection = false;
                std::cout << "Invalid direction! Use T (top), B (bottom), L (left), or R (right)." << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            game.play(row - 1, col - 1, direction); // pushes user's input to the game & adjusts for 0-based indexing
        }
        
        std::cout << game;
        
        switch (game.status()) {
        case Game::Status::PLAYER_1_WINS:
            std::cout << "Player 1 (X) wins!" << std::endl;
            break;
        case Game::Status::PLAYER_2_WINS:
            std::cout << "Player 2 (O) wins!" << std::endl;
            break;
        case Game::Status::DRAW:
            std::cout << "It's a tie!" << std::endl;
            break;
        default:
            break;

        }
        
        std::cout << "Play Again? (Y/N): ";
        std::cin >> playAgain;

        if (playAgain == 'Y' || playAgain == 'y') {
            game.reset();
        }
    }
    
    std::cout << "Goodbye!" << std::endl;
    return 0;
}