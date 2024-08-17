
#include "raylib.h"

int main() {
    // Initialize the window
    InitWindow(800, 600, "Raylib Example: Text Inside Circle");
    SetTargetFPS(60);

    // Define text and circle properties
    const char* text = "Inside";
    int circleRadius = 100;
    Vector2 circleCenter = { 400, 300 }; // Center of the circle
    int fontSize = 20;

    // Main game loop
    while (!WindowShouldClose()) {
        // Update

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw the circle
        DrawCircleV(circleCenter, circleRadius, LIGHTGRAY);

        // Calculate text size and position
        Vector2 textSize = MeasureTextEx(GetFontDefault(), text, fontSize, 1);
        Vector2 textPosition = {
            circleCenter.x - textSize.x / 2,
            circleCenter.y - textSize.y / 2
        };

        // Draw the text inside the circle
        DrawTextEx(GetFontDefault(), text, textPosition, fontSize, 1, BLACK);

        EndDrawing();
    }

    // Close window and OpenGL context
    CloseWindow();

    return 0;
}

