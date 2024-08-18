#include "layout.h"
#include <raylib.h>
#include <cstddef>
#include <ctime>
#include <cstdlib>


Layout::Layout(int width, int height, int spacing) {
    this->height = height;
    this->spacing = spacing;
    this->width = width;

}

void Layout::DrawLayout() {
    for (int x = 0; x < width; x += spacing) {
        DrawLine(x, 0, x, height, LIGHTGRAY);
    }
    for (int y = 0; y < height; y += spacing) {
        DrawLine(0, y, width, y, LIGHTGRAY);
    }
}

Vector2 GetRandomPosition(int width, int height, int spacing) {
    srand(static_cast<unsigned int>(time(NULL))); 
    int columns = width / spacing;
    int rows = height / spacing;
    int x = (rand() % (columns - 1)) * spacing;
    int y = (rand() % (rows - 1)) * spacing;
    return Vector2{(float)x, (float)y};
}



