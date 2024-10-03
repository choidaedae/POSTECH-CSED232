#include"menu.h"
#include"ashapelist.h"
#include<iostream>

using namespace std;

Menu::Menu(WhiteBoard *board, AShapeList* shape_list) { // 대입 생성자 
	
	is_running = true; // menu를 만드는 순간 is_running은 참이 되어야 함. 
	this->shape_list = shape_list;
	this->board = board;

	
}

Menu::~Menu() {



}

void Menu::display () const { // 메뉴 출력 함수 

	cout << "===============" << endl;
	cout << "[===========]" << endl;
	cout << "[Select Menu]" << endl;
	cout << "[===========]" << endl;
	cout << "1. add new shape" << endl;
	cout << "2. delete existing shape" << endl;
	cout << "3. exit" << endl;
	cout << ">>";

}


bool Menu::getRunning() const { // 현재 프로그램이 실행 중인지의 여부를 true, false로 리턴 

	return is_running;  

}


void Menu::getUserInput() { 

	int inc = 0; // 입력 커맨드 

		cin >> inc;

		if (inc == 1) {
		
			addAShape();

		}

		else if (inc == 2) {

			deleteAShape();

		}

		else if (inc == 3) {
			is_running = false;
			cout << "Exit program";
		}

		else { // 1.메뉴 예외 처리 
			
			cout << "Error: Invalid input, Type again" << endl;
		}



}


void Menu::addAShape() const { // 유저의 입력을 받아 새 도형 추가 

	char alphabet;
	int x_start;
	int x_end;
	int y_start;
	int y_end;
	int _size = 0;
	bool exceed_x = false, exceed_y = false;;

		cout << "[Add New AShape]" << endl;
		cout << "Enter Alphabet >>";
		cin >> alphabet;
		cout << "Enter x_start >>";
		cin >> x_start;
		cout << "Enter x_end >>";
		cin >> x_end;
		cout << "Enter y_start >>";
		cin >> y_start;
		cout << "Enter y_end >>";
		cin >> y_end;

		if (x_start > x_end) { //예외처리 A - x좌표

			cout << "Error: x_start exceed x_end" << endl;
			exceed_x = true;
	
		}

		if (y_start > y_end) { //예외처리 A - y좌표 

			cout << "Error: y_start exceed y_end" << endl;
			exceed_y = true;
		}

		if (exceed_x || exceed_y) return;

		else if (x_start<0 || x_end<0 || y_start<0 || y_end<0 ) { //예외처리 B


			cout << "Error: coordinate cannot be negative value" << endl;
			return;
		

		}

		else if (x_start < 0 || x_end >14 || y_start < 0 || y_end > 14) { //예외처리 C


			cout << "your input exceed whiteboard size" << endl;
			return;
		
		}



		if (x_start == x_end && y_start == y_end) { // 점

			_size = 1; 

			shape_list->addNewAShape(new APoint(x_start, y_start, alphabet));
			cout << "New APoint added with size: "<< _size << endl;
			return;
		}

		else if (x_start == x_end && y_start != y_end) { // 수직선 

			_size = y_end - y_start + 1;

			shape_list->addNewAShape(new AVerticalLine(x_start, y_start, y_end, alphabet));
			cout << "New AVerticalLine added with size: " << _size << endl;
			return;

		}

		else if (x_start != x_end && y_start == y_end) { // 수평선 

			_size = x_end - x_start + 1;

			shape_list->addNewAShape(new AHorizontalLine(y_start, x_start, x_end, alphabet));
			cout << "New AHorizontalLine added with size: " << _size << endl;
			return;

		}

		else if (x_start != x_end && y_start != y_end) { // 직사각형 

			_size = (x_end - x_start + 1) * (y_end - y_start + 1);

			shape_list->addNewAShape(new ARectangle(x_start, y_start, x_end, y_end, alphabet));
			cout << "New ARectangle added with size: " << _size << endl;
			return;

		}

	
	


}

void Menu::deleteAShape() const { // 유저의 입력을 받아 도형 삭제 

	if (shape_list->getsize() == 0) { // 예외처리 - 리스트가 비어있을 경우 

		cout << "AShape is empty." << endl;

		return;
	}

	cout << "Choose index of AShape that you want to remove" << endl;
	shape_list->displayAShapeList(); // shape_list 출력 
	int idx = 0;
	cout << ">>";
	cin >> idx;

	if (idx < 0 || idx >= shape_list->getsize()) { // 예외처리 - 인덱스 밖의 범위 
		cout << "Error: index exceed size of AShapeList" << endl;

		return;
	}

	else delete shape_list->popNodeByIdx(idx); //삭제 대상 노드 리턴받아서 동적할당 해제 

}