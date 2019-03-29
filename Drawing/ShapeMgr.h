#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.

class ShapeMgr
{
private:
	vector < DrawingShape*> drawptr;
public:
	ShapeMgr(){
		drawptr = {};
	}

	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		if (whichShape == CIRCLE) {
			drawptr.push_back(new Circle (color, pos));
		}
		else if (whichShape == SQUARE) {
			drawptr.push_back(new Square(color, pos));
		}
	}

	void read(fstream & file){

		shapeData data;

		while (file.read(reinterpret_cast<char *>(&data), sizeof(data))){
			addShape(data.position, data.shape, Color(data.color));
		}

	}

	void write(fstream & file){

		shapeData data;

		for (int i = 0; i < drawptr.size(); i++){

			data = drawptr[i]->getFileRecord();

			file.write(reinterpret_cast<char*>(&data), sizeof(data));

		}

	}

	vector<DrawingShape*> getvector() {

		return drawptr;

	}
};
