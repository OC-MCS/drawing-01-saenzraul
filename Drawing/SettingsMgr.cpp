#include<SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include"Shape.h"
#include"SettingsMgr.h"

using namespace std;
using namespace sf;

SettingsMgr(Color startingColor, ShapeEnum startingShape)
{

}

Color getCurColor()
{
	return Color::Blue; // just to make it compile 
}


ShapeEnum getCurShape()
{
	return ShapeEnum::CIRCLE; // just to make it compile;
}