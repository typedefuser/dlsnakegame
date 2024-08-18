#include "raylib.h"
#include"layout.h"

int main() {
    // Initialize the window
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Raylib Example: Text Inside Circle");
    SetTargetFPS(60);

    Layout drawer(screenWidth, screenHeight, 50);
   
    // Main game loop
    while (!WindowShouldClose()) {
        // Update

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        drawer.DrawLayout();
        drawer.DrawTarget();
        
        EndDrawing();
    }

    // Close window and OpenGL context
    CloseWindow();

    return 0;
}