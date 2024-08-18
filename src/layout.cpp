#include "layout.h"
#include <raylib.h>
#include <cstdlib>
#include <ctime>

Layout::Layout(int width, int height, int spacing) {
    this->height = height;
    this->spacing = spacing;
    this->width = width;
    srand(static_cast<unsigned int>(time(NULL)));
    
    
    int columns = width / spacing;
    int rows = height / spacing;
        
    ball_x = (rand() % columns) * spacing;
    ball_y = (rand() % rows)* spacing;
}

void Layout::DrawLayout() {
    for (int x = 0; x < width; x += spacing) {
        DrawLine(x, 0, x, height, LIGHTGRAY);
    }
    for (int y = 0; y < height; y += spacing) {
        DrawLine(0, y, width, y, LIGHTGRAY);
    }
}

void Layout::DrawTarget() {
    
    float radius = spacing / 2.0f - 2;
    DrawCircle(ball_x + spacing / 2, ball_y + spacing / 2, radius, RED);
    
    // debug
    // DrawText(TextFormat("ball_x: %d", ball_x), 10, 10, 20, BLACK);
    // DrawText(TextFormat("ball_y: %d", ball_y), 10, 40, 20, BLACK);
    // DrawText(TextFormat("rand(): %d", r), 10, 70, 20, BLACK);
}