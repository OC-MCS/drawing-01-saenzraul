#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"
#include"SettingsUI.h"

SettingsUI::SettingsUI(SettingsMgr *mgr) {
	ptr = mgr;
}

void SettingsUI::handleMouseUp(Vector2f mouse){

	if (blueButton.getGlobalBounds().contains(mouse)){
		ptr->setCurrentColor(Color::Blue);
	}
	else if (redButton.getGlobalBounds().contains(mouse)){
		ptr->setCurrentColor(Color::Red);
	}
	else if (greenButton.getGlobalBounds().contains(mouse)){
		ptr->setCurrentColor(Color::Green);
	}

	if (circleButton.getGlobalBounds().contains(mouse))	{
		ptr->setCurrentShape(CIRCLE);		
	}
	else if (rectButton.getGlobalBounds().contains(mouse))	{
		ptr->setCurrentShape(SQUARE);
	}
}

void SettingsUI::draw(RenderWindow& win) {

	Vector2f pos1(75, 100);
	redButton.setPosition(pos1);
	redButton.setRadius(25);
	redButton.setOutlineThickness(2);
	redButton.setOutlineColor(Color::Red);
	redButton.setFillColor(Color::Transparent);

	Vector2f pos3(75, 160);
	blueButton.setPosition(pos1);
	blueButton.setRadius(25);
	blueButton.setOutlineThickness(2);
	blueButton.setOutlineColor(Color::Blue);
	blueButton.setFillColor(Color::Transparent);

	Vector2f pos2(75, 220);
	greenButton.setPosition(pos1);
	greenButton.setRadius(25);
	greenButton.setOutlineThickness(2);
	greenButton.setOutlineColor(Color::Green);
	greenButton.setFillColor(Color::Transparent);

	Vector2f pos4(75, 325);
	circleButton.setPosition(pos4);
	circleButton.setRadius(20);
	circleButton.setOutlineThickness(2);
	circleButton.setOutlineColor(Color::White);
	circleButton.setFillColor(Color::Transparent);

	Vector2f pos5(75, 400);
	rectButton.setPosition(pos5);
	rectButton.setOutlineColor(Color::White);
	rectButton.setSize(Vector2f(40, 40));
	rectButton.setFillColor(Color::Transparent);

	if (ptr->getCurColor() == Color::Red) {
		redButton.setFillColor(Color::Red);
	}
	else if (ptr->getCurColor() == Color::Green) {
		greenButton.setFillColor(Color::Green);
	}
	else if (ptr->getCurColor() == Color::Blue) {
		greenButton.setFillColor(Color::Blue);
	}

	if (ptr->getCurShape() == SQUARE) {
		rectButton.setFillColor(Color::White);
	}
	else if (ptr->getCurShape() == CIRCLE) {
		circleButton.setFillColor(Color::White);
	}

	win.draw(redButton);
	win.draw(greenButton);
	win.draw(blueButton);
	win.draw(rectButton);
	win.draw(circleButton);
}