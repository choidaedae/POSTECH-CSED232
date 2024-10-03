#pragma once
#include<iostream>
#include "ashapelist.h"
#include "whiteboard.h"
class Menu 
{ 


private :
	bool is_running;
	AShapeList* shape_list;
	WhiteBoard* board;

public:
	Menu(WhiteBoard* board, AShapeList* shape_list);
	~Menu();
	void display() const;
	bool getRunning() const;
	void getUserInput();
	void addAShape() const;
	void deleteAShape() const;


};