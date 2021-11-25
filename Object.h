#pragma once

class Object
{
public:
	Object(int x, int y, char symbol, bool isSolid);

	void getCoordinates(int* x, int* y);
	void setCoordinates(int x, int y);
	void OnInteract();
	void update();
	void draw(char** screen, int cornerX, int cornerY);

protected:
	int x;
	int y;
	char symbol;
	bool isSolid;
};
