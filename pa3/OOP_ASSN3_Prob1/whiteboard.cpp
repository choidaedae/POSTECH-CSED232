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

void WhiteBoard::fillpoint(int x, int y, char alphabet) { // ������ x,y��ǥ�� ���� alphabet���� ĭ�� ä��. 

	board[y][x] = alphabet;


}

void WhiteBoard::reset() { //��� ĭ�� *�� �ʱ�ȭ 

	for (int i = 0; i < 15; i++) {

		for (int j = 0; j < 15; j++) {

			board[i][j]= '*';
		}
	}

}

void WhiteBoard::display() const { //whiteboard ��� 

	cout << "[WhiteBoard]" << endl;
	for (int i = 0; i < 15; i++) {

		for (int j = 0; j < 15; j++) {

			cout << board[i][j];
		}
		cout << endl;
	}
	cout << "===============" << endl;
}