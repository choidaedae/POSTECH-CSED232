#include "ashape.h"
#include <iostream>

using namespace std;

//AShape Class

AShape::AShape() { // 기본 생성자 

	alphabet = 'a';
	
}

AShape::~AShape() {


}

//APoint Class

APoint::APoint() { // 기본 생성자 

	x = 0;
	y = 0;
	alphabet = 'a';

}

APoint::APoint(int x_, int y_, char alphabet_) { // 대입 생성자 

	x = x_;
	y = y_;
	alphabet = alphabet_;


}

APoint::~APoint() {// 기본 소멸자 


}


void APoint::draw(WhiteBoard* board) const { // 보드에 그려주는 함수 

	board->fillpoint(x, y, alphabet);

}

void APoint::print() const {

	cout << "APoint with [alphabet: " << alphabet << "] and [x: " << x << "] and [y: " << y << "] and [size: "<< size() << "]" << endl;

}

int APoint::size() const {

	return 1;

}

// AVerticalLine Class

AVerticalLine::AVerticalLine() { // 기본 생성자 

	x = 0;
	y_start = 0;
	y_end = 0;
	alphabet = 'a';


}

AVerticalLine::AVerticalLine(int x_, int y_start_, int y_end_, char alphabet_) // 대입 생성자 
{

	x = x_;
	y_start = y_start_;
	y_end = y_end_;
	alphabet = alphabet_;
	
}

AVerticalLine::~AVerticalLine() {// 기본 소멸자 


}


void AVerticalLine::draw(WhiteBoard* board) const { // 보드에 그려주는 함수 

	for (int i = y_start; i <= y_end; i++) {

		board->fillpoint(x, i, alphabet);

	}



}

void AVerticalLine::print() const {


	cout << "AVerticalLine with [alphabet: " << alphabet << "] and [x: " << x << "] and [y_start: " << y_start << "] and [y_end: " << y_end << "] and [size: " << size() << "]" << endl;
}

int AVerticalLine::size() const {


	return (y_end - y_start + 1);
}

// AHorizontalLine Class

AHorizontalLine::AHorizontalLine() { // 기본 생성자 

	x_start = 0;
	x_end = 0;
	y = 0;
	alphabet = 'a';



}


AHorizontalLine::AHorizontalLine(int y_, int x_start_, int x_end_, char alphabet_) {  // 대입 생성자 

	y = y_;
	x_start = x_start_;
	x_end = x_end_;
	alphabet = alphabet_;
}

AHorizontalLine::~AHorizontalLine() {// 기본 소멸자 


}


void AHorizontalLine::draw(WhiteBoard* board) const { // 보드에 그려주는 함수 

	
	
	for (int i = x_start; i <= x_end; i++) {

		board->fillpoint(i, y, alphabet);

	}



}

void AHorizontalLine::print() const {

	cout << "AHorizontalLine with [alphabet: " << alphabet << "] and [y: " << y << "] and [x_start: " << x_start << "] and [x_end: " << x_end << "] and [size: " << size() << "]" << endl;

}

int AHorizontalLine::size() const {

	return (x_end - x_start + 1) ;

}

//ARectangle Class

ARectangle::ARectangle() { // 기본 생성자 

	x_start = 0;
	x_end = 0;
	y_start = 0;
	y_end = 0;
	alphabet = 'a';



}

ARectangle::ARectangle(int x_start_, int y_start_, int x_end_, int y_end_, char alphabet_) { // 대입 생성자 

	x_start = x_start_;
	y_start = y_start_;
	x_end = x_end_;
	y_end = y_end_;
	alphabet = alphabet_;

}

ARectangle::~ARectangle() { //기본 소멸자 


}


void ARectangle::draw(WhiteBoard* board) const { // 보드에 그려주는 함수 

	for (int i = x_start; i <= x_end; i++) {

		for (int j = y_start; j <= y_end; j++) {

			board->fillpoint(i, j, alphabet);
		}

	}


}

void ARectangle::print() const {


	cout << "ARentangle with [alphabet: " << alphabet << "] and [x_start: " << x_start << "] and [x_end: " << x_end << "] and [y_start: " << y_start << "] and [y_end: " << y_end << "] and [size: " << size() << "]" << endl;
}

int ARectangle::size() const {


	return (x_end - x_start + 1) * (y_end - y_start + 1);

}

