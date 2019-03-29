#include <iostream>
#include "Shape.h"

using namespace std;
using namespace sf;

DrawingShape::DrawingShape() {

}

DrawingShape::DrawingShape(ShapeEnum shape, Color color, Vector2f pos) {
	this->shape = shape;
	this->color = color;
	this->pos = pos;
}

ShapeEnum DrawingShape::getShape(){

	return shape;

}

Color DrawingShape::getColor(){

	return color;

}

Vector2f DrawingShape::getPos(){

	return pos;

}


Circle::Circle(ShapeEnum shape, Color color, Vector2f pos) : DrawingShape(color, pos)

{

	circle.setRadius(10);

	circle.setOutlineThickness(2);

}

void Circle::Draw(RenderWindow &win)

{

	circle.setPosition(getPos());

	circle.setOutlineColor(getColor());

	circle.setFillColor(getColor());



	win.draw(circle);

}

CircleShape Circle::getCircle()

{

	return circle;

}

shapeData Circle::getFileRecord()

{


	shapeData circleData; 

	circleData.shape = getShape();


	unsigned colorNumber = getColor().toInteger;
	circleData.color = colorNumber;

	circleData.pos = getPos();



	return circleData;

}

Square::Square(ShapeEnum shape, Color color, Vector2f pos) : DrawingShape(shape, color, pos)

{

	square.setSize(Vector2f(SIZE, SIZE));

	square.setOutlineThickness(2);

}

void Square::Draw(RenderWindow &win)

{

	//Sets circle data and draws it

	square.setPosition(getPos());

	square.setOutlineColor(getColor());

	square.setFillColor(getColor());



	win.draw(square);

}

RectangleShape Square::getSquare()

{

	return square;

}

shapeData Square::getFileRecord()

{

	

	shapeData squareData; 

	squareData.shape = getShape();

	unsigned colorNumber = getColor().toInteger;
	squareData.color = colorNumber;

	squareData.color = colorNumber;

	squareData.pos = getPos();



	return squareData;

}

