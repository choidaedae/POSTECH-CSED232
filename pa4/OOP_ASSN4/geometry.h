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
rectangle<T>::rectangle() { //기본 생성자 , 별도로 구현하지는 않음 


}

template<typename T>
rectangle<T>::rectangle(const T& x1, const T& y1, const T& x2, const T& y2) {

	T xbig, xsmall, ybig, ysmall; // x1와 x2 사이에 순서를 부여함 

	xbig = x1 > x2 ? x1 : x2;  
	xsmall = x1 <= x2 ? x1 : x2; 
	ybig = y1 > y2 ? y1 : y2;
	ysmall = y1 <= y2 ? y1 : y2;

	this->x1 = xsmall;
	this->x2 = xbig;
	this->y1 = ysmall;
	this->y2 = ybig;

	T area = (x1 - x2) * (y1 - y2);

	if (area == 0) throw; // 직사각형의 넓이가 0이 되는 경우 throw함. 



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
bool rectangle<T>::is_equal(const rectangle<T>& other) { // 같은 경우 


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
bool rectangle<T>::is_line_overlap(const rectangle<T>& other) { // 한 변을 공유하는 경우 

	if (is_equal(other)) return false;
	if (is_intersect(other)) return false;


	if (this->x2 == other.x1 && y_overlap(other)) return true;
	if (this->x1 == other.x2 && y_overlap(other)) return true;
	if (this->y2 == other.y1 && x_overlap(other)) return true;
	if (this->y1 == other.y2 && x_overlap(other)) return true;


	else return false;
}

template<typename T>
bool rectangle<T>::is_point_match(const rectangle<T>& other) { // 한 점에서 만나는 경우 

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

	else return true; //나머지 모든 상황에 대해 disjoint



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
			isfill[i][j] = 1; //비어있지 않다는 표시 

		}
	}


}


template<typename T, int N>
point<T, N>::point() { // 기본 생성자, 별도로 구현하진 않음 


}

template<typename T, int N>
point<T, N>::~point() {


}


template<typename T, int N>
point <T, N>::point(const T* coords) { //복사 생성자
	for (int i = 0; i < 5; i++) {

		this->dimarr[i] = coords[i];
	}
}


template<typename T, int N>
void point <T, N>::draw2canvas(float** board, int **isfill, int height, int width ) { // 보드에 표시해주는 함수 

	
	int y=0, x=0;
	float val = 0.0;
	bool d2 = false;

	for (int i = 0; i < 5; i++) {

		if (i == 0) { //배열의 첫 번째 값이 x임.
			if (this->dimarr[i] < 0 || this->dimarr[i] >= width) return;
			else x = int(this->dimarr[i]); 
		
		}
		if (i == 1) { //배열의 두 번째 값은 y임 
			if (this->dimarr[i] < 0 || this->dimarr[i] >= height) return;
			else y = int(this->dimarr[i]); 
		}

		if (i > 1) val += (this->dimarr[i]); // 2차원 이상부터는 값 더해줌 (마지막에 버림)

		
	}



	if (val == 0.0) d2 = true; // val값이 0이면 2차원이다.

	if (d2) {  //2차원인 경우 
		isfill[y][x] = 1;
		board[y][x] += 1; // 1을 더함 
	}

	else { //3차원 이상인 경우 
		isfill[y][x] = 1;
		board[y][x] += val; //  val을 더함
	}
	




}


