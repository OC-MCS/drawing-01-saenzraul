#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

// finish this code; add functions, data as needed

class SettingsUI
{
private:
	SettingsMgr * ptr;
	CircleShape redButton;
	CircleShape greenButton;
	CircleShape blueButton;
	CircleShape circleButton;
	RectangleShape rectButton;
public:
	SettingsUI(SettingsMgr *mgr);
	void handleMouseUp(Vector2f mouse);
	void draw(RenderWindow& win);
};
