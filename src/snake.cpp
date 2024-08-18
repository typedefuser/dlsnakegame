#include "snake.h"
#include<raylib.h>

void Ball::DrawBall(){
    float radius = size/ 2.0f - 2;
    DrawCircle(position.x + size/2, position.y + size/2, radius, RED); 
}


void Snake::DrawSnake(){
    DrawRectangle(position.x, position.y, size, size, GREEN);
}
