#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include"geometry.h"


using namespace std;
class canvas2d : public vector<geometry*> 
{

public: 


	canvas2d(int width, int height, char c_empty);
	~canvas2d();
	void draw2stdout();
	

private:

	int width;
	int height;
	char c;
	float** board;
	int** isfill;
};

canvas2d::canvas2d(int width, int height, char c_empty) {  // 생성자 

	this->width = width;
	this->height = height;
	this->c = c_empty;
	this->board = new float* [height];
	this->isfill = new int* [height];

	for (int i = 0; i < height; i++) { // 2차원 배열 동적할당 

		board[i] = new float[width]{};

	}

	for (int i = 0; i < height; i++) {

		isfill[i] = new int[width]{};

	}

	for (int i = 0; i < this->height; i++) {

		for (int j = 0; j < this->width; j++) {

			board[i][j] = 0.0; //  초기화 
			isfill[i][j] = 0;
		}
	}
}

canvas2d::~canvas2d() { // 소멸자, 동적할당 해제 

	for (int i = 0; i < height; ++i) delete[] board[i]; //보드 할당 해제 
	delete[] board;

	for (int i = 0; i < height; ++i) delete[] isfill[i]; 
	delete[] isfill;

	int size = this->size(); // geometry* 에 대해 할당 해제 
	for (int i = 0; i < size; i++) {

		auto* pg = this->back();
		pop_back();

		delete[] pg;


	}


}

void canvas2d::draw2stdout() {

	geometry* newg = NULL;


	for (int i = 0; i < this->size(); i++) {

		newg = *(this->begin() + i);
		newg->draw2canvas(this->board, this->isfill, this->height, this->width); //draw2canvas값 호출 

	}


	for (int i = 0; i < this->height; i++) {

		for (int j = 0; j < this->width; j++) {

			if (isfill[i][j] == 0) std::cout << this->c; // 비어있으면 c_empty 출력하기 

			else std::cout << ((int)this->board[i][j]) % 10; //채워져있으면 값 출력하기

		}
		std::cout << std::endl;
	}


}