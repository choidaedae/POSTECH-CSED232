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

canvas2d parser::parse_canvas(const std::string& line) { // string �ɰ��� board �׸��� �Լ� 

	istringstream ssline(line);
	string temp = "";
	getline(ssline, temp, ','); //���� ���� ������ ��: width
	int nwidth = stoi(temp);
	getline(ssline, temp, ','); //�ι�°�� ������ ��: height
	int nheight = stoi(temp);
	getline(ssline, temp, '\0'); // ������ �κ� 
	char nc = (temp.c_str())[0]; // �׻� 1������

	canvas2d *pc = new canvas2d(nwidth, nheight, nc); //canvas ��ü ����

	return *pc; //��ü ���� 

}


geometry* parser::parse_geometry(const std::string& line) { //string �ɰ��� ���� ��ü �����ϴ� �Լ� 

	istringstream ssline(line);
	string temp = "";

	getline(ssline, temp, ','); // ó�� �߶� ������ ��: ���� ���� 

	if (temp == "rectangle") {
		getline(ssline, temp, ','); // �� ��° �߶� ������ ��: datatype

		if (temp == "int") {

			int arr[5] = {};
			int dim = 0;
			while (getline(ssline, temp, ',')) { // �� ���� ���� �� ���� ,�� ������ parsing�� (��, ��������) 

				arr[dim] = stoi(temp);
				dim++;
			}

			rectangle<int>* pr = new rectangle<int>(arr[0], arr[1], arr[2], arr[3]); // ���� �Ҵ� �� �����ڷ� ����

			return pr; //������ ����

		}


		else if (temp == "float") { // float�� ���

			float arr[5] = {};
			int dim = 0;
			while (getline(ssline, temp, ',')) {

				arr[dim] = stof(temp); // �迭�� �� �־��� 
				dim++;
			}
			rectangle<float>* pr = new rectangle<float>(arr[0], arr[1], arr[2], arr[3]); // �����ڷ� �����԰� ���ÿ� �����Ҵ� 


			return pr; // ������ ���� 

		}


	}

	else if (temp == "point") { //point �� ��� 
		getline(ssline, temp, ',');

		if (temp == "int") {

			int arr[5] = {};
			int dim = 0;
			while (getline(ssline, temp, ',')) {

				arr[dim] = stoi(temp); // �迭�� �� �־��� 
				dim++;
			}
			point <int, 5>* pp = new point<int, 5>(arr); // �����ڷ� �����԰� ���ÿ� �����Ҵ� 


			return pp; // ������ ���� 

		}


		else if (temp == "float") { 

			float arr[5] = {};
			int dim = 0;
			while (getline(ssline, temp, ',')) {

				arr[dim] = stof(temp); // �迭�� �� �־���
				dim++;
			}
			point <float, 5>* pp = new point<float, 5>(arr); // �����ڷ� �����԰� ���ÿ� �����Ҵ� 

			return pp; // ������ ���� 

		}


	}
	else return NULL;

}