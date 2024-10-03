#include "Vector_Rider.h"


Vector_Rider::Vector_Rider() { //Vector_Rider 기본 생성자 
	//값 초기화한 상태로 생성 
	_size = 0;
	_capacity = 0;
	arr = NULL;

}

Vector_Rider::Vector_Rider(int size) { //Vector_Rider size 지정 생성자 


	arr = new Rider [size] {};
	_capacity = size;
	_size = size;


}

Vector_Rider::Vector_Rider(int size, const Rider& init) {  //size와 값이 지정된 rider을 가져와서 생성하는 생성자 

	arr = new Rider [size] {}; // 동적 할당 
	for (int i = 0; i < size; i++) arr[i] = init; // arr에 init 값 대입

	_capacity = size;
	_size = size;


}

Vector_Rider::Vector_Rider(int size, const Rider* init) { //size와 값이 지정된 rider 배열을 가져와서 생성하는 생성자 

	arr = new Rider[size] {}; // 동적 할당 
	for (int i = 0; i < size; i++) arr[i] = init[i];

	_capacity = size;
	_size = size;

}

Vector_Rider::Vector_Rider(const Vector_Rider& v) { //Rider 복사 생성자 

	arr = new Rider[v._capacity]; // 동적 할당
	_size = v._size;
	_capacity = v._capacity;


	for (int i = 0; i < v._size; i++) { 

		arr[i] = v.arr[i];
	}

}

Vector_Rider::~Vector_Rider() { //소멸자 

	if (arr != NULL) delete[] arr; //동적할당 해제 
}

int Vector_Rider::capacity() const { //_capacity를 리턴하는 함수 

	return _capacity;
}

int Vector_Rider::size() const { //_size를 리턴하는 함수 

	return _size;
}

Vector_Rider::iterator Vector_Rider::begin() { //배열의 첫 주소를 리턴하는 함수 (const)

	return arr;

}

Vector_Rider::const_iterator Vector_Rider::begin() const { //배열의 첫 주소를 리턴하는 함수 (const)

	return arr;

}

Vector_Rider::iterator Vector_Rider::end() { //배열의 끝 주소를 리턴하는 함수 

	return arr + _size;

}

Vector_Rider::const_iterator Vector_Rider::end() const { //배열의 끝 주소를 리턴하는 함수 (const)

	return arr + _size;

}

Rider& Vector_Rider::front() { //배열의 첫 값을 가져오는 함수 

	return *arr;

}

const Rider& Vector_Rider::front() const { //배열의 첫 값을 가져오는 함수 (const)

	return  *arr;

}
 
Rider& Vector_Rider::back() { //배열의 끝 값을 가져오는 함수 

	return *(arr + _size - 1);

}

const Rider& Vector_Rider::back() const { //배열의 끝 값을 가져오는 함수 (const)

	return  *(arr + _size - 1);

}

void Vector_Rider::allocate(int capacity) { // size 그대로 capacity 바뀜


	this->arr = new Rider[capacity] {};
	this->_capacity = capacity;

}

void Vector_Rider::resize(int size) { // size,  capacity 바뀜

	Rider* temp = new Rider[_capacity] {}; // 동적 할당
	for (int i = 0; i < _size; i++) temp[i] = arr[i];
	delete[] arr; //arr 동적할당 해제 
	int oldsize = _size;
	_size = size;
	_capacity = size;
	arr = new Rider[_size] {}; //arr 재할당

	if (size > oldsize) { //사이즈가 늘어났을 경우 

		for (int i = 0; i < oldsize; i++) arr[i] = temp[i];

	}

	else for (int i = 0; i < size; i++) arr[i] = temp[i]; // 사이즈가 줄었을 경우 

}

void Vector_Rider::push_back(const Rider& value) { 

	Rider* temp = new Rider[_capacity] {}; // 동적 할당 
	for (int i = 0; i < _size; i++) temp[i] = arr[i]; // 임시 배열에 대입 
	delete[] arr; // 동적할당 해제 

	_size++;

	if (_size >= _capacity) {
		if (_size < 5) {

			arr = new Rider[_size] {};
			_capacity = _size;

		}
		else {
			arr = new Rider[_size * 2]{};
			_capacity = _size * 2;
		}
	}

	for (int i = 0; i < _size - 1; i++) {
		arr[i] = temp[i];

	}
	arr[_size - 1] = value;
}


void Vector_Rider::pop_back() {

	_size--;

}

void Vector_Rider::insert(iterator position, const Rider& value) {

	int pos = 0;
	Rider* temp = new Rider[_capacity] {};
	for (int i = 0; i < _size; i++) temp[i] = arr[i];
	delete[] arr;
	_size++;
	if (_size > _capacity) {
		if (_size < 5) {
			arr = new Rider[_size] {};
			_capacity = _size;
		}
		else {
			arr = new Rider[_size * 2]{};
			_capacity = _size * 2;
		}
	}

	for (int i = 0; i < _size; i++) {

		if ((arr + i) == position) {

			pos = i;
			break;

		}
	}

	for (int i = 0; i < pos; i++) { 

		arr[i] = temp[i];
	}

	arr[pos] = value; //pos 인덱스에 값 대입 

	for (int i = pos + 1; i < _size; i++) { // 하나 밀린 채로 대입

		arr[i] = temp[i - 1];
	}

}

void Vector_Rider::insert(iterator position, const Rider* first, const Rider* last) {

	int old_size = _size; // 이전 사이즈 저장 
	int interval = last - first; // 주소의 간격
	int datanum = interval; //data 개수
	int pos = 0; // 삽입 위치(인덱스)를 저장하는 변수 
	Rider* temp = new Rider[_capacity] {}; // 임시 배열 동적 할당  
	int cur = 0;
	if (arr != NULL) {
		for (int i = 0; i < _size; i++)
			temp[i] = arr[i];


	}

	_size += datanum;

	if (_size > _capacity) {
		if (_size < 5) {
			arr = new Rider[_size] {}; //arr 재할당
			_capacity = _size;
		}
		else {
			arr = new Rider[_size * 2]{}; //arr 재할당
			_capacity = _size * 2;
		}

	}

	for (int i = 0; i < _size; i++) {

		if ((arr + i) == position) {

			pos = i;
			break;

		}
	}

	for (int i = 0; i < pos; i++) { 

		arr[i] = temp[i]; 
	}

	for (int i = pos; i < pos + datanum; i++) { 

		arr[i] = *(first + cur);
		cur++;
	}

	for (int i = pos + datanum; i < _size; i++) {

		arr[i] = temp[i - datanum];
	}
}



void Vector_Rider::erase(iterator position) {
	
	int index = position - this->begin();
	for (int i = index; i < _size - 1; i++) {

		arr[i] = arr[i + 1];

	}
	_size--;

}

void Vector_Rider::clear() { // Vector 내부를 비워주는 함수 


	for (int i = 0; i < _size; i++) { 

		Rider temp(0, 0, 0);
		arr[i] = temp;

	} 
	_capacity = 0;
	_size = 0;

}

Rider& Vector_Rider::operator[](int index) { //연산자 오버로딩 

	if (index >= 0 && index < _size) {

		return arr[index];
	}

	
}

const Rider& Vector_Rider::operator[](int index) const { // 연산자 오버로딩(const)


	if (index >= 0 && index < _size) { 

		return arr[index];
	}


}

Vector_Rider& Vector_Rider::operator=(const Vector_Rider& v) { // 대입 연산자 오버로딩 


	this->arr = NULL;
	this->_size = v._size; // 값 가져옴 
	this->_capacity = v._capacity;


	this->arr = new Rider[this->_capacity]; //  동적할당 해제 

	for (int i = 0; i < this->_size; i++) // 배열 요소를 하나씩 넣어줌 
		this->arr[i] = v.arr[i];


	return *this;

}

