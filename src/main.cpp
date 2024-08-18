#include <raylib.h>
#include"layout.h"
#include "snake.h"
#include <iostream>

int main() {
    // Initialize the window
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Snake Game");
    SetTargetFPS(60);
    const int spacing=50;
    //layout created
    Layout drawer(screenWidth, screenHeight,spacing);

    // Generate random positions for snake and ball
    //Vector2 snakePosition = GetRandomPosition(screenWidth, screenHeight, spacing);
    Vector2 ballPosition = GetRandomPosition(screenWidth, screenHeight, spacing);

    //snake created
    Snake snake({0,0}, spacing);
    snake.speed=(float)spacing/5;
    
    Ball ball(ballPosition, spacing);
    
    // Main game loop
    while (!WindowShouldClose()) {


// Update
if (IsKeyDown(KEY_W)) {
    snake.SetPosition(Vector2{snake.GetPosition().x, snake.GetPosition().y - snake.speed});
    // Check if snake is above the top boundary
    if (snake.GetPosition().y < 0) {
        snake.SetPosition(Vector2{snake.GetPosition().x, screenHeight - snake.GetSize()}); // Wrap around to the bottom
    }
}
if (IsKeyDown(KEY_S)) {
    snake.SetPosition(Vector2{snake.GetPosition().x, snake.GetPosition().y + snake.speed});
    // Check if snake is below the bottom boundary
    if (snake.GetPosition().y > screenHeight - snake.GetSize()) {
        snake.SetPosition(Vector2{snake.GetPosition().x, 0}); // Wrap around to the top
    }
}
if (IsKeyDown(KEY_A)) {
    snake.SetPosition(Vector2{snake.GetPosition().x - snake.speed, snake.GetPosition().y});
    // Check if snake is to the left of the left boundary
    if (snake.GetPosition().x < 0) {
        snake.SetPosition(Vector2{screenWidth - snake.GetSize(), snake.GetPosition().y}); // Wrap around to the right
    }
}
if (IsKeyDown(KEY_D)) {
    snake.SetPosition(Vector2{snake.GetPosition().x + snake.speed, snake.GetPosition().y});
    // Check if snake is to the right of the right boundary
    if (snake.GetPosition().x > screenWidth - snake.GetSize()) {
        snake.SetPosition(Vector2{0, snake.GetPosition().y}); // Wrap around to the left
    }
}




        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        drawer.DrawLayout();
        snake.DrawSnake();
        ball.DrawBall();
        
        EndDrawing();
    }

    // Close window and OpenGL context
    CloseWindow();

    return 0;
}
