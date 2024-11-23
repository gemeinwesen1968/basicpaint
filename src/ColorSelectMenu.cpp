#include "ColorSelectMenu.h"

ColorSelectMenu::ColorSelectMenu() {
	
	colors[0] = RED;
	colors[1] = BLUE;
	colors[2] = BROWN;
	colors[3] = PINK;
	colors[4] = ORANGE;
	colors[5] = GREEN;
	colors[6] = YELLOW;
	colors[7] = PURPLE;

	for (int i = 0; i < 8; i++) {
		buttons[i].n = 6;
		buttons[i].color = colors[i];
		buttons[i].fCoordX = i * buttons[i].n * buttons[i].n;
		buttons[i].fCoordY = 0;
	}
}

void ColorSelectMenu::draw() {
	for (colorButton button : buttons) {
		DrawRectangle(button.fCoordX + 1, button.fCoordY + 1, button.n * button.n - 2, button.n * button.n - 2, button.color);
	}
}