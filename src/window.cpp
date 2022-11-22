#include "../include/player.h"
#include "../include/window.h"

using namespace std;

Player snake;

void Window::init() {
     currentScreen = LOGO;

     InitWindow(SCREENWIDTH, SCREENHEIGHT, "Snake Dak");
     InitAudioDevice();
     SetTargetFPS(60);

     fxWav = LoadSound("ressources/food.wav");

     snake.PlayerInit({ 10, 10 }, cellSize);
     snake.size = 2;
}

void Window::CloseGame() {
    CloseAudioDevice();
    CloseWindow();
}

void Window::resetGame() {
    ClearBackground(BLACK);
    snake.size = 1;
    framesCounter = 0;
    snake.dead = false;

    currentScreen = GAMEPLAY;

    snake.dir = 0;
    snake.PlayerInit({ 10, 10 }, cellSize);
    snake.size = 2;
}


void Window::RunGame()
{
    while (!WindowShouldClose())
    {
        if (framesCounter == 50) { currentScreen = TITLE; framesCounter++; }

        BeginDrawing();

        if (snake.dead)
        {
            DrawText("u lost", SCREENWIDTH / 2 - 30, SCREENHEIGHT / 2, 30, WHITE);
            DrawText("press Space to start the game", SCREENWIDTH / 2 - 30, SCREENHEIGHT / 2 + 30, 30, WHITE);
            if (IsKeyDown(KEY_SPACE)) {
                ClearBackground(BLACK);
                resetGame();
                ClearBackground(BLACK);
            }
        }

        ClearBackground(BLACK);

        switch (currentScreen)
        {
        case LOGO:
            DrawText("made by pigeon", SCREENWIDTH / 2 - 30, SCREENHEIGHT / 2, 30, WHITE);
            framesCounter++;
            break;
        case TITLE:
            DrawText("press Space to start the game", SCREENWIDTH / 2 - 30, SCREENHEIGHT / 2, 30, WHITE);
            ClearBackground(BLACK);
            if (IsKeyDown(KEY_SPACE)) { currentScreen = GAMEPLAY; }
            break;
    case GAMEPLAY:
            if (!snake.dead) {
                snake.direction();
            }

            snake.DrawPlayer();

            if (!snake.hasEaten) {
                snake.spawnFood();
            }

            DrawRectangle(snake.foodPosX, snake.foodPosY, cellSize, cellSize, GREEN);

        }

        EndDrawing();
    }
}

void Window::start(){
    init();

    RunGame();

    CloseGame();
}

