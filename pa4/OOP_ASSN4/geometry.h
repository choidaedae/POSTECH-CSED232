#pragma once
#include<iostream>


class geometry {

public:
	
	geometry();
	virtual ~geometry();
	virtual void draw2canvas(float** board, int **isfill, int height, int width) = 0;


	float dimarr[5]={};
	int dims = 5;

};

template<typename T>
class rectangle : public geometry {

public:

	rectangle<T>(const T&, const T&, const T&, const T&);
	rectangle<T>();
	~rectangle();
	bool is_equal(const rectangle<T>&);
	bool is_intersect(const rectangle<T>&);
	bool is_line_overlap(const rectangle<T>&);
	bool is_point_match(const rectangle<T>&);
	bool is_disjoint(const rectangle<T>&);
	void draw2canvas(float **board, int **isfill, int height, int width);
	bool x_overlap(const rectangle<T>& other);
	bool y_overlap(const rectangle<T>& other);

private:

	T x1;
	T x2;
	T y1;
	T y2;


};

template<typename T, int N>
class point :public geometry {
public:

	point<T, N>();
	~point();
	point <T, N>(const T*);
	void draw2canvas(float **board, int **isfill, int height, int width);



private:

};


geometry::geometry() {


}
geometry:: ~geometry() {


}


template<typename T>
rectangle<T>::rectangle() { //�⺻ ������ , ������ ���������� ���� 


}

template<typename T>
rectangle<T>::rectangle(const T& x1, const T& y1, const T& x2, const T& y2) {

	T xbig, xsmall, ybig, ysmall; // x1�� x2 ���̿� ������ �ο��� 

	xbig = x1 > x2 ? x1 : x2;  
	xsmall = x1 <= x2 ? x1 : x2; 
	ybig = y1 > y2 ? y1 : y2;
	ysmall = y1 <= y2 ? y1 : y2;

	this->x1 = xsmall;
	this->x2 = xbig;
	this->y1 = ysmall;
	this->y2 = ybig;

	T area = (x1 - x2) * (y1 - y2);

	if (area == 0) throw; // ���簢���� ���̰� 0�� �Ǵ� ��� throw��. 



}

template<typename T>
rectangle<T>:: ~rectangle() { 



}


template<typename T>
bool rectangle<T>::x_overlap(const rectangle<T>& other) {

	if (other.x2<this->x1) return false;
	if (other.x2==this->x1) return false;
	if (other.x1 > this->x2) return false;
	if (other.x1 == this->x2) return false;


	else return true;

}

template<typename T>
bool rectangle<T>::y_overlap(const rectangle<T>& other) {

	if (this->y1 >= other.y2) return false;
	if (this->y2 <= other.y1) return false;

	else return true;

}

template<typename T>
bool rectangle<T>::is_equal(const rectangle<T>& other) { // ���� ��� 


	if (this->x1 == other.x1 && this->x2 == other.x2 && this->y1 == other.y1 && this->y2 == other.y2) return true;
	else return false;

}

template<typename T>
bool rectangle<T>::is_intersect(const rectangle<T>& other) {

	if (is_equal(other)) return false;


	if (x_overlap(other) && y_overlap(other)) return true;


	else return false;

	

}

template<typename T>
bool rectangle<T>::is_line_overlap(const rectangle<T>& other) { // �� ���� �����ϴ� ��� 

	if (is_equal(other)) return false;
	if (is_intersect(other)) return false;


	if (this->x2 == other.x1 && y_overlap(other)) return true;
	if (this->x1 == other.x2 && y_overlap(other)) return true;
	if (this->y2 == other.y1 && x_overlap(other)) return true;
	if (this->y1 == other.y2 && x_overlap(other)) return true;


	else return false;
}

template<typename T>
bool rectangle<T>::is_point_match(const rectangle<T>& other) { // �� ������ ������ ��� 

	if (is_intersect(other)) return false;

	if (this->x2 == other.x1 && this->y1 == other.y2) return true;
	else if (this->x2 == other.x1 && this->y2 == other.y1) return true;
	else if (this->x1 == other.x2 && this->y2 == other.y1) return true;
	else if (this->x1 == other.x2 && this->y1 == other.y2) return true;

	else return false;

}

template<typename T>
bool rectangle<T>::is_disjoint(const rectangle<T>& other) {
	
	if (is_equal(other) == true) return false;
	else if (is_intersect(other) == true) return false;
	else if (is_line_overlap(other) == true) return false;
	else if (is_point_match(other) == true) return false;

	else return true; //������ ��� ��Ȳ�� ���� disjoint



}

template<typename T>
void rectangle<T>::draw2canvas(float** board, int **isfill, int height, int width) {

	int xmax = width-1 < x2 ? width-1 : x2;
	int xmin = 0 > x1 ? 0 : x1;
	int ymax = height-1 < y2 ? height-1 : y2;
	int ymin = 0 > y1 ? 0 : y1;



	for (int i = ymin; i <= ymax; i++) {

		for (int j = xmin; j <= xmax; j++) {
			
			board[i][j] += 1.0;
			isfill[i][j] = 1; //������� �ʴٴ� ǥ�� 

		}
	}


}


template<typename T, int N>
point<T, N>::point() { // �⺻ ������, ������ �������� ���� 


}

template<typename T, int N>
point<T, N>::~point() {


}


template<typename T, int N>
point <T, N>::point(const T* coords) { //���� ������
	for (int i = 0; i < 5; i++) {

		this->dimarr[i] = coords[i];
	}
}


template<typename T, int N>
void point <T, N>::draw2canvas(float** board, int **isfill, int height, int width ) { // ���忡 ǥ�����ִ� �Լ� 

	
	int y=0, x=0;
	float val = 0.0;
	bool d2 = false;

	for (int i = 0; i < 5; i++) {

		if (i == 0) { //�迭�� ù ��° ���� x��.
			if (this->dimarr[i] < 0 || this->dimarr[i] >= width) return;
			else x = int(this->dimarr[i]); 
		
		}
		if (i == 1) { //�迭�� �� ��° ���� y�� 
			if (this->dimarr[i] < 0 || this->dimarr[i] >= height) return;
			else y = int(this->dimarr[i]); 
		}

		if (i > 1) val += (this->dimarr[i]); // 2���� �̻���ʹ� �� ������ (�������� ����)

		
	}



	if (val == 0.0) d2 = true; // val���� 0�̸� 2�����̴�.

	if (d2) {  //2������ ��� 
		isfill[y][x] = 1;
		board[y][x] += 1; // 1�� ���� 
	}

	else { //3���� �̻��� ��� 
		isfill[y][x] = 1;
		board[y][x] += val; //  val�� ����
	}
	




}


