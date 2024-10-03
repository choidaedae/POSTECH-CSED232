#include "whiteboard.h"
#include <iostream>

using namespace std;

WhiteBoard::WhiteBoard()  {


	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {

			board[i][j] = 'a';
		}
	}


}

WhiteBoard::~WhiteBoard() {


}

void WhiteBoard::fillpoint(int x, int y, char alphabet) { // 지정된 x,y좌표에 들어온 alphabet으로 칸을 채움. 

	board[y][x] = alphabet;


}

void WhiteBoard::reset() { //모든 칸을 *로 초기화 

	for (int i = 0; i < 15; i++) {

		for (int j = 0; j < 15; j++) {

			board[i][j]= '*';
		}
	}

}

void WhiteBoard::display() const { //whiteboard 출력 

	cout << "[WhiteBoard]" << endl;
	for (int i = 0; i < 15; i++) {

		for (int j = 0; j < 15; j++) {

			cout << board[i][j];
		}
		cout << endl;
	}
	cout << "===============" << endl;
}