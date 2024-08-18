#ifndef LAYOUT_H
#define LAYOUT_H


class Layout{
	private:
		int width,height,spacing,ball_x,ball_y;
	
	public:
		Layout(int width,int height,int spacing);
        void DrawLayout();
		void DrawTarget();
};

#endif