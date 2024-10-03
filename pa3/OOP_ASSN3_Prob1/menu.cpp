#include"menu.h"
#include"ashapelist.h"
#include<iostream>

using namespace std;

Menu::Menu(WhiteBoard *board, AShapeList* shape_list) { // ���� ������ 
	
	is_running = true; // menu�� ����� ���� is_running�� ���� �Ǿ�� ��. 
	this->shape_list = shape_list;
	this->board = board;

	
}

Menu::~Menu() {



}

void Menu::display () const { // �޴� ��� �Լ� 

	cout << "===============" << endl;
	cout << "[===========]" << endl;
	cout << "[Select Menu]" << endl;
	cout << "[===========]" << endl;
	cout << "1. add new shape" << endl;
	cout << "2. delete existing shape" << endl;
	cout << "3. exit" << endl;
	cout << ">>";

}


bool Menu::getRunning() const { // ���� ���α׷��� ���� �������� ���θ� true, false�� ���� 

	return is_running;  

}


void Menu::getUserInput() { 

	int inc = 0; // �Է� Ŀ�ǵ� 

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

		else { // 1.�޴� ���� ó�� 
			
			cout << "Error: Invalid input, Type again" << endl;
		}



}


void Menu::addAShape() const { // ������ �Է��� �޾� �� ���� �߰� 

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

		if (x_start > x_end) { //����ó�� A - x��ǥ

			cout << "Error: x_start exceed x_end" << endl;
			exceed_x = true;
	
		}

		if (y_start > y_end) { //����ó�� A - y��ǥ 

			cout << "Error: y_start exceed y_end" << endl;
			exceed_y = true;
		}

		if (exceed_x || exceed_y) return;

		else if (x_start<0 || x_end<0 || y_start<0 || y_end<0 ) { //����ó�� B


			cout << "Error: coordinate cannot be negative value" << endl;
			return;
		

		}

		else if (x_start < 0 || x_end >14 || y_start < 0 || y_end > 14) { //����ó�� C


			cout << "your input exceed whiteboard size" << endl;
			return;
		
		}



		if (x_start == x_end && y_start == y_end) { // ��

			_size = 1; 

			shape_list->addNewAShape(new APoint(x_start, y_start, alphabet));
			cout << "New APoint added with size: "<< _size << endl;
			return;
		}

		else if (x_start == x_end && y_start != y_end) { // ������ 

			_size = y_end - y_start + 1;

			shape_list->addNewAShape(new AVerticalLine(x_start, y_start, y_end, alphabet));
			cout << "New AVerticalLine added with size: " << _size << endl;
			return;

		}

		else if (x_start != x_end && y_start == y_end) { // ���� 

			_size = x_end - x_start + 1;

			shape_list->addNewAShape(new AHorizontalLine(y_start, x_start, x_end, alphabet));
			cout << "New AHorizontalLine added with size: " << _size << endl;
			return;

		}

		else if (x_start != x_end && y_start != y_end) { // ���簢�� 

			_size = (x_end - x_start + 1) * (y_end - y_start + 1);

			shape_list->addNewAShape(new ARectangle(x_start, y_start, x_end, y_end, alphabet));
			cout << "New ARectangle added with size: " << _size << endl;
			return;

		}

	
	


}

void Menu::deleteAShape() const { // ������ �Է��� �޾� ���� ���� 

	if (shape_list->getsize() == 0) { // ����ó�� - ����Ʈ�� ������� ��� 

		cout << "AShape is empty." << endl;

		return;
	}

	cout << "Choose index of AShape that you want to remove" << endl;
	shape_list->displayAShapeList(); // shape_list ��� 
	int idx = 0;
	cout << ">>";
	cin >> idx;

	if (idx < 0 || idx >= shape_list->getsize()) { // ����ó�� - �ε��� ���� ���� 
		cout << "Error: index exceed size of AShapeList" << endl;

		return;
	}

	else delete shape_list->popNodeByIdx(idx); //���� ��� ��� ���Ϲ޾Ƽ� �����Ҵ� ���� 

}