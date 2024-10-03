#include "Vector.h"


Vector::Vector() { // default constructor

	_size = 0;
	_capacity = 0;
	arr = NULL;
	
}

Vector::Vector(int size) { //constructor


	arr = new float [size]{};

	_capacity = size;
	_size = size;


}

Vector::Vector(int size, const float& init) { //constructor

	arr = new float [size] {};
	for (int i = 0; i < size; i++) arr[i] = init;
	
	_capacity = size;
	_size = size;


}

Vector::Vector(int size, const float* init) { // constructor

	arr = new float[size] {};
	for (int i = 0; i < size; i++) arr[i] = init[i];

	_capacity = size;
	_size = size;

}

Vector::Vector(const Vector& v) { //constructor

	if (arr != NULL) delete[] arr;
	
	arr = new float[v._capacity]; 
	_size = v._size;
	_capacity = v._capacity;

	

	for (int i = 0; i < v._size; i++) {

		arr[i] = v.arr[i];
	}

}

Vector::~Vector() { //destructor

	if (arr != NULL) delete[] arr;
}

int Vector::capacity() const{ // _capacity를 return하는 함수 

	return _capacity;
}

int Vector::size() const {  // _size를 return하는 함수 

	return _size;
}

Vector::iterator Vector::begin() { //시작 주소 

	return arr;

}

Vector::const_iterator Vector::begin() const { // 시작 주소 (const)

	return arr;

}

Vector::iterator Vector::end() { // 끝 주소 

	return arr+_size;

}

Vector::const_iterator Vector::end() const { // 끝 주소 (const)

	return arr + _size;

}

float& Vector::front() { // 시작 값

	return *arr;

}

const float& Vector::front() const{ //시작 값

	return  *arr;

}

float& Vector::back() { // 끝 값

	return *(arr+_size-1);

}

const float& Vector::back() const { // 끝 값

	return  *(arr+_size-1);

}

void Vector::allocate(int capacity) { // size 그대로 capacity 바뀜


	this->arr = new float[capacity]{};
	this->_capacity = capacity;
	
}

void Vector::resize(int size) { // size,  capacity 바뀜

	float * temp = new float[_capacity] {}; // 임시 배열 할당 
	for (int i = 0; i < _size; i++) temp[i] = arr[i]; //배열 대입 
	delete[] arr; // 원래 배열 할당 해제 
	int oldsize = _size;
	_size = size;
	_capacity = size;
	arr = new float[_size]{}; // arr 다시 할당 

	if (size > oldsize) {

		for (int i = 0; i < oldsize; i++) arr[i] = temp[i];
		
	}

	else for (int i = 0; i < size; i++) arr[i] = temp[i];

	delete[] temp; // 동적 할당 해제 

}

void Vector::push_back(const float& value) { //벡터의 맨 끝에 data 삽입해주는 함수 

	float* temp = new float[_capacity]{};
	for(int i=0; i<_size; i++) temp[i] = arr[i];
	delete[] arr;
	
	_size++;

	if (_size >= _capacity) { // 데이터 할당 조건을 준수함. 
		if (_size < 5) { 

		arr = new float[_size] {};
		_capacity = _size; 
		
		}
		else {
		arr = new float[_size * 2]{}; 
		_capacity = _size * 2;
		}
	}

	for (int i = 0; i < _size - 1; i++) {
		arr[i] = temp[i];
		
	}
	arr[_size - 1] = value;
}


void Vector::pop_back() { // 사이즈 하나 줄임 

	_size--; 

}

void Vector::insert(iterator position, const float& value) {

	int pos=0;
	float* temp = new float[_capacity] {};
	for (int i = 0; i < _size; i++) temp[i] = arr[i];
	delete[] arr; 
	_size++;
	if (_size > _capacity) { // 데이터 할당 조건을 준수함. 
		if (_size < 5) { 
			arr = new float[_size]{};
			_capacity = _size;
		}
		else {
			arr = new float[_size * 2]{};
			_capacity = _size* 2;
		}
	}

	for (int i=0; i < _size; i++) {

		if ((arr + i) == position) {

			pos = i; 
			break; 

		}
	}

	for (int i = 0; i < pos; i++) {

		arr[i] = temp[i]; //삽입 전까지는 위치 똑같음. 
	}

	arr[pos] = value;

	for (int i = pos + 1; i < _size; i++) { // 한 칸 밀림. 

		arr[i] = temp[i - 1];
	}

	delete[] temp;

}

void Vector::insert(iterator position, const float* first, const float* last) {

	int old_size = _size; //이전 사이즈 기억
	int interval = last - first; // 간격
	int datanum = interval; //삽입 데이터 개수 
	int pos = 0; //삽입 위치(인덱스)
	float* temp = new float[_capacity] {}; // 임시 배열 선언 및 초기화 
	int cur = 0;
	if (arr != NULL) {
		for (int i = 0; i < _size; i++) 
			temp[i] = arr[i];

	}

	_size += datanum; // 사이즈는 늘어남.


	if (_size > _capacity) { // 데이터 할당 조건을 준수함. 
		if (_size < 5) { 
			arr = new float[_size] {};
			_capacity = _size;
		}
		else { 
			arr = new float[_size * 2]{}; 
			_capacity = _size * 2;
		}

	}

	for (int i = 0; i < _size; i++) { // 삽입 위치를 찾는 과정 

		if ((arr + i) == position) {

			pos = i;
			break;

		}
	}

	for (int i = 0; i < pos; i++) { // 삽입 전까지는 데이터 위치 그대로 

		arr[i] = temp[i];
	}

	for (int i = pos; i < pos+datanum; i++) { //datanum개수만큼 삽입 

		arr[i] = *(first+cur);
		cur++;
	}

	for (int i = pos+datanum; i < _size; i++) { // datanum 개수만큼 위치가 밀렸음. 

		arr[i] = temp[i-datanum];
	}

	delete[] temp;
}



void Vector::erase(iterator position) { 
	int pos = 0;

	for (int i = 0; i < _size; i++) { // 삭제 위치를 찾는 과정 

		if ((arr + i) == position) {
			pos = i;
			break;

		}
	}
	_size--;
	for (int i = pos; i < _size; i++) { // 한 칸씩 당겨주는 과정 
		arr[i] = arr[i + 1];
	}

	arr[_size] = 0; // 맨 뒤 값을 없애줌 

}

void Vector::clear() { //벡터를 비우는 함수 

	
	for (int i = 0; i < _size; i++) arr[i] = 0; 
	_capacity = 0;
	_size = 0;

}

float& Vector::operator[](int index) { // [] 연산자 오버로딩 

	if (index >= 0 && index < _size) {

		return arr[index];
	}

}

const float& Vector::operator[](int index) const { // []연산자 오버로딩 (const 버전)

	
	if (index >= 0 && index < _size) {

		return arr[index];
	}

}

Vector& Vector::operator=(const Vector& v) { // = 연산자 오버로딩(클래스 간의 deep copy)
	
	
	delete []arr; // 초기화
	this->_size = v._size;
	this->_capacity = v._capacity;
	
	
	this->arr = new float[this->_capacity];

	for (int i = 0; i < this->_size; i++) 
		arr[i] = v.arr[i];
	

	return *this;

}