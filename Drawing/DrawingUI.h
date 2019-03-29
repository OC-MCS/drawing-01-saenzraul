#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

// finish this code; add functions, data as needed

class DrawingUI
{
private:
	RectangleShape rect;
public:
	DrawingUI(Vector2f p){
		p.x = 0;
		p.y = 0;
	}

	void draw(RenderWindow& win, ShapeMgr *mgr){
		Vector2f pos(150, 25);
		rect.setPosition(pos);
		rect.setOutlineThickness(4);
		rect.setOutlineColor(Color::White);
		rect.setSize(Vector2f(615, 550));
		rect.setFillColor(Color::Transparent);
		win.draw(rect);

		vector<DrawingShape*> ptr;

		ptr = mgr->getvector();

		for (int x = 0; x < ptr.size(); x++) {
			ptr[x]->Draw(win);
		}
	}
	
	bool isMouseInCanvas(Vector2f mousePos){
		bool isValid = true;
		if(!rect.getGlobalBounds().contains(mousePos)){
			isValid = false;
		}
		return isValid; // just to make it compile
	}

};

