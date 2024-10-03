#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct p_info{

	string place;
	int anni;

};

void sel_sort(p_info iu_photo[], int photo_num); // ���������ϴ� �Լ�
void swap(int *a, int *b); // swap �Լ� 

int main() {

	ifstream fin("input.txt"); // ���� ���� 
	ofstream fout("output.txt");
	p_info iu_photo[100]; //�����͸� ������ �迭 ���� 

	int data = 0; //data ���� �����ϴ� ���� 

	while (fin.eof() == 0) { 
		
		fin >> iu_photo[data].anni >> iu_photo[data].place;
		data++;

	}

	sel_sort(iu_photo, data); // ���� ���� �κ��� �Լ��� ������. 

	for (int j = 0; j < data; j++) fout << iu_photo[j].anni <<" "<< iu_photo[j].place << endl;
	fin.close();
	fout.close();

	return 0;
}

void sel_sort(p_info iu_photo[], int photo_num) { // iu_photo �迭�� �ҷ��� �� ���������ϴ� �Լ� 

	int min_idx; // �ּҰ��� �ε����� �����ϴ� ���� 
	string temp; // string���� �ٲ� �� �ӽ÷� string�� ������ ���� 
	
	for (int i = 0; i < photo_num; i++) {

		min_idx = i; // �ʱ� min_idx�� i�� �ʱ�ȭ 

		for (int j = i+1; j < photo_num; j++) {

			if (iu_photo[min_idx].anni > iu_photo[j].anni) { // ������ �� ���� ���� �������� ���� 
				min_idx = j; 
			}

			else if (iu_photo[min_idx].anni == iu_photo[j].anni) { // ������ ������ ��Ҹ� ���ĺ� �������� ���� 

				if (iu_photo[min_idx].place.compare(iu_photo[j].place)>0) min_idx = j;
					
			}
			
		}
		
		swap(&iu_photo[i].anni, &iu_photo[min_idx].anni); // int������ �±�ȯ: swap�Լ��� ���� 
		temp = iu_photo[min_idx].place; // string������ �±�ȯ: ���� �Լ��� ���������� ����. 
		iu_photo[min_idx].place = iu_photo[i].place;
		iu_photo[i].place = temp;
	}
}

void swap(int *a, int *b) { //pointer�� ����ؼ� swap�Լ��� ������

	int temp = *a;
	*a = *b;
	*b = temp;

}

