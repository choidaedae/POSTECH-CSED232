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

void sel_sort(p_info iu_photo[], int photo_num); // 선택정렬하는 함수
void swap(int *a, int *b); // swap 함수 

int main() {

	ifstream fin("input.txt"); // 파일 열기 
	ofstream fout("output.txt");
	p_info iu_photo[100]; //데이터를 저장할 배열 변수 

	int data = 0; //data 개수 저장하는 변수 

	while (fin.eof() == 0) { 
		
		fin >> iu_photo[data].anni >> iu_photo[data].place;
		data++;

	}

	sel_sort(iu_photo, data); // 선택 정렬 부분을 함수로 구현함. 

	for (int j = 0; j < data; j++) fout << iu_photo[j].anni <<" "<< iu_photo[j].place << endl;
	fin.close();
	fout.close();

	return 0;
}

void sel_sort(p_info iu_photo[], int photo_num) { // iu_photo 배열을 불러온 뒤 선택정렬하는 함수 

	int min_idx; // 최소값의 인덱스를 저장하는 변수 
	string temp; // string끼리 바꿀 때 임시로 string을 저장할 변수 
	
	for (int i = 0; i < photo_num; i++) {

		min_idx = i; // 초기 min_idx를 i로 초기화 

		for (int j = i+1; j < photo_num; j++) {

			if (iu_photo[min_idx].anni > iu_photo[j].anni) { // 연도가 더 빠른 것을 기준으로 정렬 
				min_idx = j; 
			}

			else if (iu_photo[min_idx].anni == iu_photo[j].anni) { // 연도가 같으면 장소를 알파벳 오름차순 정렬 

				if (iu_photo[min_idx].place.compare(iu_photo[j].place)>0) min_idx = j;
					
			}
			
		}
		
		swap(&iu_photo[i].anni, &iu_photo[min_idx].anni); // int끼리의 맞교환: swap함수로 구현 
		temp = iu_photo[min_idx].place; // string끼리의 맞교환: 따로 함수로 구현하지는 않음. 
		iu_photo[min_idx].place = iu_photo[i].place;
		iu_photo[i].place = temp;
	}
}

void swap(int *a, int *b) { //pointer를 사용해서 swap함수를 구현함

	int temp = *a;
	*a = *b;
	*b = temp;

}

