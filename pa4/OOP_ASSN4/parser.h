#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include"geometry.h"
#include"canvas2d.h"


class parser {

public:
	canvas2d parse_canvas(const std::string&);
	geometry* parse_geometry(const std::string&);
};

using namespace std;

canvas2d parser::parse_canvas(const std::string& line) { // string 쪼개서 board 그리는 함수 

	istringstream ssline(line);
	string temp = "";
	getline(ssline, temp, ','); //가장 먼저 나오는 값: width
	int nwidth = stoi(temp);
	getline(ssline, temp, ','); //두번째로 나오는 값: height
	int nheight = stoi(temp);
	getline(ssline, temp, '\0'); // 나머지 부분 
	char nc = (temp.c_str())[0]; // 항상 1글자임

	canvas2d *pc = new canvas2d(nwidth, nheight, nc); //canvas 객체 생성

	return *pc; //객체 리턴 

}


geometry* parser::parse_geometry(const std::string& line) { //string 쪼개서 기하 객체 선언하는 함수 

	istringstream ssline(line);
	string temp = "";

	getline(ssline, temp, ','); // 처음 잘라서 나오는 값: 도형 종류 

	if (temp == "rectangle") {
		getline(ssline, temp, ','); // 두 번째 잘라서 나오는 값: datatype

		if (temp == "int") {

			int arr[5] = {};
			int dim = 0;
			while (getline(ssline, temp, ',')) { // 한 줄이 끝날 때 까지 ,을 단위로 parsing함 (즉, 차원값임) 

				arr[dim] = stoi(temp);
				dim++;
			}

			rectangle<int>* pr = new rectangle<int>(arr[0], arr[1], arr[2], arr[3]); // 동적 할당 및 생성자로 생성

			return pr; //포인터 리턴

		}


		else if (temp == "float") { // float인 경우

			float arr[5] = {};
			int dim = 0;
			while (getline(ssline, temp, ',')) {

				arr[dim] = stof(temp); // 배열에 값 넣어줌 
				dim++;
			}
			rectangle<float>* pr = new rectangle<float>(arr[0], arr[1], arr[2], arr[3]); // 생성자로 생성함과 동시에 동적할당 


			return pr; // 포인터 리턴 

		}


	}

	else if (temp == "point") { //point 인 경우 
		getline(ssline, temp, ',');

		if (temp == "int") {

			int arr[5] = {};
			int dim = 0;
			while (getline(ssline, temp, ',')) {

				arr[dim] = stoi(temp); // 배열에 값 넣어줌 
				dim++;
			}
			point <int, 5>* pp = new point<int, 5>(arr); // 생성자로 생성함과 동시에 동적할당 


			return pp; // 포인터 리턴 

		}


		else if (temp == "float") { 

			float arr[5] = {};
			int dim = 0;
			while (getline(ssline, temp, ',')) {

				arr[dim] = stof(temp); // 배열에 값 넣어줌
				dim++;
			}
			point <float, 5>* pp = new point<float, 5>(arr); // 생성자로 생성함과 동시에 동적할당 

			return pp; // 포인터 리턴 

		}


	}
	else return NULL;

}