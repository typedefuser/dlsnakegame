#ifndef SNAKE_H
#define SNAKE_H
#include<raylib.h>


class Snake {
private:
    Vector2 position;
    float size;

public:
    int speed;
    Snake(Vector2 pos, float s) : position(pos), size(s) {}
    void DrawSnake();
    Vector2 GetPosition() const { return position; } 
    float GetSize() const { return size; } 
    void SetPosition(Vector2 newPosition) { position = newPosition; } 
};


class Ball {
private:
    Vector2 position;
    float size;

public:
    Ball(Vector2 pos, float s) : position(pos), size(s) {}
    void DrawBall();
};


#endif
