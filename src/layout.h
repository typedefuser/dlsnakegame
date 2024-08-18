#ifndef LAYOUT_H
#define LAYOUT_H
#include<raylib.h>


class Layout{
	private:
		int width,height,spacing;
	
	public:
		Layout(int width,int height,int spacing);
        void DrawLayout();
};

// Function to generate a random position within the layout
Vector2 GetRandomPosition(int width, int height, int spacing);


#endif