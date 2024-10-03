#include "Vector_Rider.h"


Vector_Rider::Vector_Rider() { //Vector_Rider �⺻ ������ 
	//�� �ʱ�ȭ�� ���·� ���� 
	_size = 0;
	_capacity = 0;
	arr = NULL;

}

Vector_Rider::Vector_Rider(int size) { //Vector_Rider size ���� ������ 


	arr = new Rider [size] {};
	_capacity = size;
	_size = size;


}

Vector_Rider::Vector_Rider(int size, const Rider& init) {  //size�� ���� ������ rider�� �����ͼ� �����ϴ� ������ 

	arr = new Rider [size] {}; // ���� �Ҵ� 
	for (int i = 0; i < size; i++) arr[i] = init; // arr�� init �� ����

	_capacity = size;
	_size = size;


}

Vector_Rider::Vector_Rider(int size, const Rider* init) { //size�� ���� ������ rider �迭�� �����ͼ� �����ϴ� ������ 

	arr = new Rider[size] {}; // ���� �Ҵ� 
	for (int i = 0; i < size; i++) arr[i] = init[i];

	_capacity = size;
	_size = size;

}

Vector_Rider::Vector_Rider(const Vector_Rider& v) { //Rider ���� ������ 

	arr = new Rider[v._capacity]; // ���� �Ҵ�
	_size = v._size;
	_capacity = v._capacity;


	for (int i = 0; i < v._size; i++) { 

		arr[i] = v.arr[i];
	}

}

Vector_Rider::~Vector_Rider() { //�Ҹ��� 

	if (arr != NULL) delete[] arr; //�����Ҵ� ���� 
}

int Vector_Rider::capacity() const { //_capacity�� �����ϴ� �Լ� 

	return _capacity;
}

int Vector_Rider::size() const { //_size�� �����ϴ� �Լ� 

	return _size;
}

Vector_Rider::iterator Vector_Rider::begin() { //�迭�� ù �ּҸ� �����ϴ� �Լ� (const)

	return arr;

}

Vector_Rider::const_iterator Vector_Rider::begin() const { //�迭�� ù �ּҸ� �����ϴ� �Լ� (const)

	return arr;

}

Vector_Rider::iterator Vector_Rider::end() { //�迭�� �� �ּҸ� �����ϴ� �Լ� 

	return arr + _size;

}

Vector_Rider::const_iterator Vector_Rider::end() const { //�迭�� �� �ּҸ� �����ϴ� �Լ� (const)

	return arr + _size;

}

Rider& Vector_Rider::front() { //�迭�� ù ���� �������� �Լ� 

	return *arr;

}

const Rider& Vector_Rider::front() const { //�迭�� ù ���� �������� �Լ� (const)

	return  *arr;

}
 
Rider& Vector_Rider::back() { //�迭�� �� ���� �������� �Լ� 

	return *(arr + _size - 1);

}

const Rider& Vector_Rider::back() const { //�迭�� �� ���� �������� �Լ� (const)

	return  *(arr + _size - 1);

}

void Vector_Rider::allocate(int capacity) { // size �״�� capacity �ٲ�


	this->arr = new Rider[capacity] {};
	this->_capacity = capacity;

}

void Vector_Rider::resize(int size) { // size,  capacity �ٲ�

	Rider* temp = new Rider[_capacity] {}; // ���� �Ҵ�
	for (int i = 0; i < _size; i++) temp[i] = arr[i];
	delete[] arr; //arr �����Ҵ� ���� 
	int oldsize = _size;
	_size = size;
	_capacity = size;
	arr = new Rider[_size] {}; //arr ���Ҵ�

	if (size > oldsize) { //����� �þ�� ��� 

		for (int i = 0; i < oldsize; i++) arr[i] = temp[i];

	}

	else for (int i = 0; i < size; i++) arr[i] = temp[i]; // ����� �پ��� ��� 

}

void Vector_Rider::push_back(const Rider& value) { 

	Rider* temp = new Rider[_capacity] {}; // ���� �Ҵ� 
	for (int i = 0; i < _size; i++) temp[i] = arr[i]; // �ӽ� �迭�� ���� 
	delete[] arr; // �����Ҵ� ���� 

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

	arr[pos] = value; //pos �ε����� �� ���� 

	for (int i = pos + 1; i < _size; i++) { // �ϳ� �и� ä�� ����

		arr[i] = temp[i - 1];
	}

}

void Vector_Rider::insert(iterator position, const Rider* first, const Rider* last) {

	int old_size = _size; // ���� ������ ���� 
	int interval = last - first; // �ּ��� ����
	int datanum = interval; //data ����
	int pos = 0; // ���� ��ġ(�ε���)�� �����ϴ� ���� 
	Rider* temp = new Rider[_capacity] {}; // �ӽ� �迭 ���� �Ҵ�  
	int cur = 0;
	if (arr != NULL) {
		for (int i = 0; i < _size; i++)
			temp[i] = arr[i];


	}

	_size += datanum;

	if (_size > _capacity) {
		if (_size < 5) {
			arr = new Rider[_size] {}; //arr ���Ҵ�
			_capacity = _size;
		}
		else {
			arr = new Rider[_size * 2]{}; //arr ���Ҵ�
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

void Vector_Rider::clear() { // Vector ���θ� ����ִ� �Լ� 


	for (int i = 0; i < _size; i++) { 

		Rider temp(0, 0, 0);
		arr[i] = temp;

	} 
	_capacity = 0;
	_size = 0;

}

Rider& Vector_Rider::operator[](int index) { //������ �����ε� 

	if (index >= 0 && index < _size) {

		return arr[index];
	}

	
}

const Rider& Vector_Rider::operator[](int index) const { // ������ �����ε�(const)


	if (index >= 0 && index < _size) { 

		return arr[index];
	}


}

Vector_Rider& Vector_Rider::operator=(const Vector_Rider& v) { // ���� ������ �����ε� 


	this->arr = NULL;
	this->_size = v._size; // �� ������ 
	this->_capacity = v._capacity;


	this->arr = new Rider[this->_capacity]; //  �����Ҵ� ���� 

	for (int i = 0; i < this->_size; i++) // �迭 ��Ҹ� �ϳ��� �־��� 
		this->arr[i] = v.arr[i];


	return *this;

}

