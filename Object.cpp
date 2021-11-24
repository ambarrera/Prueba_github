#include "Object.h"

Object::Object(int x, int y, char symbol, bool isSolid) {
	this->x = x;
	this->y = y;
	this->symbol = symbol;
	this->isSolid = isSolid;
}

void Object::setCoordinates(int x, int y) {
	this->x = x;
	this->y = y;
}

void Object::OnInteract() {
	//nothing here
}

void Object::draw(char **screen, int cornerX, int cornerY) {
	screen[y + cornerY][x + cornerX];
}

void Object::update() {
	//nothing
}
