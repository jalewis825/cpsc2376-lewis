#include "dots_boxes.h"
#include "Engine.h"

int main(int argc, char* argv[]) {
    Engine engine("Dots and Boxes", 700, 700, "Ubuntu-Bold.ttf", 24, "move.wav");
    Game game(3, 3);

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                quit = true;

            if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
                int x = e.button.x;
                int y = e.button.y;

                if (game.handleClick(x, y)) {
                    engine.playSound();
                }
            }

            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_r) {
                game.reset();
            }
        }

        game.render(engine);
        SDL_Delay(16);
    }

    return 0;
}