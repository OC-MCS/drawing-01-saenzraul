#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Shape.h"
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

// finish this code; add functions, data as needed

struct settings
{
	Color lastColor; 
	ShapeEnum lastShape; 
};
class SettingsMgr
{
private:

	Color currentColor;
	ShapeEnum currentShape;

public:
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		currentColor = startingColor;
		currentShape = startingShape;
	}

	Color getCurColor()
	{
		return currentColor; // returns Current Color 
	}


	ShapeEnum getCurShape()
	{
		return currentShape; // returns Current Shape
	}

	void setCurrentColor(Color newColor) {
		currentColor = newColor;
	}

	void setCurrentShape(ShapeEnum newShape) {
		currentShape = newShape;
	}

	void read(fstream & file){
		int color;
		ShapeEnum Currentshape;
		file.read(reinterpret_cast<char *>(&color), sizeof(color));
		file.read(reinterpret_cast<char *>(&Currentshape), sizeof(Currentshape));
		currentColor = Color(color);
		currentShape = Currentshape;
	}

	void write(fstream & file){
		int color;
		color = currentColor.toInteger();
		file.write(reinterpret_cast<char *>(&color), sizeof(color));
		file.write(reinterpret_cast<char *>(&currentShape), sizeof(currentShape));
	}

};
