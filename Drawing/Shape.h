#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

enum ShapeEnum {CIRCLE, SQUARE};

struct shapeData {
	ShapeEnum shape;
	int color;
	Vector2f pos;
};


class DrawingShape 
{
private:
	shapeData drawing;
public:
	DrawingShape();
	DrawingShape(shapeData);
	virtual void Draw(RenderWindow &win) = 0;
	virtual shapeData getFileRecord() = 0;
	ShapeEnum getShape();
	Color getColor();
	Vector2f getPos();
};


class Circle : public DrawingShape {
private:
	CircleShape circle;
public:
	Circle(ShapeEnum, Color, Vector2f);
	void Draw(RenderWindow &win);
	shapeData getFileRecord();
	CircleShape getCircle();
};

class Square : public DrawingShape {
private:
	RectangleShape square;
public:
	Square(ShapeEnum, Color, Vector2f);
	void Draw(RenderWindow &win);
	shapeData getFileRecord();
	RectangleShape getSquare();
};


