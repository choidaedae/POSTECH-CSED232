#pragma once

class WhiteBoard {

private:

	char board[15][15];

public:

	WhiteBoard();
	~WhiteBoard();
	void fillpoint(int x, int y, char alphabet);
	void reset();
	void display() const;


};