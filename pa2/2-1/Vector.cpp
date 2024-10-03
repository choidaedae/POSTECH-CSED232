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

int Vector::capacity() const{ // _capacity�� return�ϴ� �Լ� 

	return _capacity;
}

int Vector::size() const {  // _size�� return�ϴ� �Լ� 

	return _size;
}

Vector::iterator Vector::begin() { //���� �ּ� 

	return arr;

}

Vector::const_iterator Vector::begin() const { // ���� �ּ� (const)

	return arr;

}

Vector::iterator Vector::end() { // �� �ּ� 

	return arr+_size;

}

Vector::const_iterator Vector::end() const { // �� �ּ� (const)

	return arr + _size;

}

float& Vector::front() { // ���� ��

	return *arr;

}

const float& Vector::front() const{ //���� ��

	return  *arr;

}

float& Vector::back() { // �� ��

	return *(arr+_size-1);

}

const float& Vector::back() const { // �� ��

	return  *(arr+_size-1);

}

void Vector::allocate(int capacity) { // size �״�� capacity �ٲ�


	this->arr = new float[capacity]{};
	this->_capacity = capacity;
	
}

void Vector::resize(int size) { // size,  capacity �ٲ�

	float * temp = new float[_capacity] {}; // �ӽ� �迭 �Ҵ� 
	for (int i = 0; i < _size; i++) temp[i] = arr[i]; //�迭 ���� 
	delete[] arr; // ���� �迭 �Ҵ� ���� 
	int oldsize = _size;
	_size = size;
	_capacity = size;
	arr = new float[_size]{}; // arr �ٽ� �Ҵ� 

	if (size > oldsize) {

		for (int i = 0; i < oldsize; i++) arr[i] = temp[i];
		
	}

	else for (int i = 0; i < size; i++) arr[i] = temp[i];

	delete[] temp; // ���� �Ҵ� ���� 

}

void Vector::push_back(const float& value) { //������ �� ���� data �������ִ� �Լ� 

	float* temp = new float[_capacity]{};
	for(int i=0; i<_size; i++) temp[i] = arr[i];
	delete[] arr;
	
	_size++;

	if (_size >= _capacity) { // ������ �Ҵ� ������ �ؼ���. 
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


void Vector::pop_back() { // ������ �ϳ� ���� 

	_size--; 

}

void Vector::insert(iterator position, const float& value) {

	int pos=0;
	float* temp = new float[_capacity] {};
	for (int i = 0; i < _size; i++) temp[i] = arr[i];
	delete[] arr; 
	_size++;
	if (_size > _capacity) { // ������ �Ҵ� ������ �ؼ���. 
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

		arr[i] = temp[i]; //���� �������� ��ġ �Ȱ���. 
	}

	arr[pos] = value;

	for (int i = pos + 1; i < _size; i++) { // �� ĭ �и�. 

		arr[i] = temp[i - 1];
	}

	delete[] temp;

}

void Vector::insert(iterator position, const float* first, const float* last) {

	int old_size = _size; //���� ������ ���
	int interval = last - first; // ����
	int datanum = interval; //���� ������ ���� 
	int pos = 0; //���� ��ġ(�ε���)
	float* temp = new float[_capacity] {}; // �ӽ� �迭 ���� �� �ʱ�ȭ 
	int cur = 0;
	if (arr != NULL) {
		for (int i = 0; i < _size; i++) 
			temp[i] = arr[i];

	}

	_size += datanum; // ������� �þ.


	if (_size > _capacity) { // ������ �Ҵ� ������ �ؼ���. 
		if (_size < 5) { 
			arr = new float[_size] {};
			_capacity = _size;
		}
		else { 
			arr = new float[_size * 2]{}; 
			_capacity = _size * 2;
		}

	}

	for (int i = 0; i < _size; i++) { // ���� ��ġ�� ã�� ���� 

		if ((arr + i) == position) {

			pos = i;
			break;

		}
	}

	for (int i = 0; i < pos; i++) { // ���� �������� ������ ��ġ �״�� 

		arr[i] = temp[i];
	}

	for (int i = pos; i < pos+datanum; i++) { //datanum������ŭ ���� 

		arr[i] = *(first+cur);
		cur++;
	}

	for (int i = pos+datanum; i < _size; i++) { // datanum ������ŭ ��ġ�� �з���. 

		arr[i] = temp[i-datanum];
	}

	delete[] temp;
}



void Vector::erase(iterator position) { 
	int pos = 0;

	for (int i = 0; i < _size; i++) { // ���� ��ġ�� ã�� ���� 

		if ((arr + i) == position) {
			pos = i;
			break;

		}
	}
	_size--;
	for (int i = pos; i < _size; i++) { // �� ĭ�� ����ִ� ���� 
		arr[i] = arr[i + 1];
	}

	arr[_size] = 0; // �� �� ���� ������ 

}

void Vector::clear() { //���͸� ���� �Լ� 

	
	for (int i = 0; i < _size; i++) arr[i] = 0; 
	_capacity = 0;
	_size = 0;

}

float& Vector::operator[](int index) { // [] ������ �����ε� 

	if (index >= 0 && index < _size) {

		return arr[index];
	}

}

const float& Vector::operator[](int index) const { // []������ �����ε� (const ����)

	
	if (index >= 0 && index < _size) {

		return arr[index];
	}

}

Vector& Vector::operator=(const Vector& v) { // = ������ �����ε�(Ŭ���� ���� deep copy)
	
	
	delete []arr; // �ʱ�ȭ
	this->_size = v._size;
	this->_capacity = v._capacity;
	
	
	this->arr = new float[this->_capacity];

	for (int i = 0; i < this->_size; i++) 
		arr[i] = v.arr[i];
	

	return *this;

}