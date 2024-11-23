#pragma once
#include "../include/raylib.h"

typedef struct {
	Color color;
	float fCoordX;
	float fCoordY;
	int n;
} colorButton;

// TODO CREATE A MENU CLASS IN ANOTHER HEADER AND MAKE COLORSELECTMENU MEMBER

class ColorSelectMenu {
public:
	Color currentColor;
	// TODO MAKE THIS MORE COSTUMIZEBLE (RGB VALUES GIVEN BY IO?)
	Color colors[8];
	colorButton buttons[8];
	ColorSelectMenu();
	void draw();
};