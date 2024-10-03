#include "Vector_Customer.h"


Vector_Customer::Vector_Customer() {

	_size = 0;
	_capacity = 0;


}

Vector_Customer::Vector_Customer(int size) {


	arr = new Customer[size]{};
	_capacity = size;
	_size = size;


}

Vector_Customer::Vector_Customer(int size, const Customer& init) {

	arr = new Customer[size]{};
	for (int i = 0; i < size; i++) arr[i] = init;

	_capacity = size;
	_size = size;


}

Vector_Customer::Vector_Customer(int size, const Customer* init) {

	arr = new Customer[size]{};
	for (int i = 0; i < size; i++) arr[i] = init[i];

	_capacity = size;
	_size = size;

}

Vector_Customer::Vector_Customer(const Vector_Customer& v) {

	arr = new Customer[v._capacity];
	_size = v._size;
	_capacity = v._capacity;



	for (int i = 0; i < v._size; i++) {

		arr[i] = v.arr[i];
	}

}

Vector_Customer::~Vector_Customer() {

	if (arr != NULL) delete[] arr;
}

int Vector_Customer::capacity() const {

	return _capacity;
}

int Vector_Customer::size() const {

	return _size;
}

Vector_Customer::iterator Vector_Customer::begin() {

	return arr;

}

Vector_Customer::const_iterator Vector_Customer::begin() const {

	return arr;

}

Vector_Customer::iterator Vector_Customer::end() {

	return arr + _size;

}

Vector_Customer::const_iterator Vector_Customer::end() const {

	return arr + _size;

}

Customer& Vector_Customer::front() {

	return *arr;

}

const Customer& Vector_Customer::front() const {

	return  *arr;

}

Customer& Vector_Customer::back() {

	return *(arr + _size - 1);

}

const Customer& Vector_Customer::back() const {

	return  *(arr + _size - 1);

}

void Vector_Customer::allocate(int capacity) { // size 그대로 capacity 바뀜


	this->arr = new Customer[capacity]{};
	this->_capacity = capacity;

}

void Vector_Customer::resize(int size) { // size,  capacity 바뀜

	Customer* temp = new Customer[_capacity]{};
	for (int i = 0; i < _size; i++) temp[i] = arr[i];
	delete[] arr;
	int oldsize = _size;
	_size = size;
	_capacity = size;
	arr = new Customer[_size]{};

	if (size > oldsize) {

		for (int i = 0; i < oldsize; i++) arr[i] = temp[i];

	}

	else for (int i = 0; i < size; i++) arr[i] = temp[i];

}

void Vector_Customer::push_back(const Customer& value) {

	Customer* temp = new Customer[_capacity]{};
	for (int i = 0; i < _size; i++) temp[i] = arr[i];
	delete[] arr;

	_size++;

	if (_size >= _capacity) {
		if (_size < 5) {

			arr = new Customer[_size]{};
			_capacity = _size;

		}
		else {
			arr = new Customer[_size * 2]{};
			_capacity = _size * 2;
		}
	}

	for (int i = 0; i < _size - 1; i++) {
		arr[i] = temp[i];

	}
	arr[_size - 1] = value;
}


void Vector_Customer::pop_back() {

	_size--;

}

void Vector_Customer::insert(iterator position, const Customer& value) {

	int pos = 0;
	Customer* temp = new Customer[_capacity]{};
	for (int i = 0; i < _size; i++) temp[i] = arr[i];
	delete[] arr;
	_size++;
	if (_size > _capacity) {
		if (_size < 5) {
			arr = new Customer[_size]{};
			_capacity = _size;
		}
		else {
			arr = new Customer[_size * 2]{};
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

	arr[pos] = value;

	for (int i = pos + 1; i < _size; i++) {

		arr[i] = temp[i - 1];
	}

}

void Vector_Customer::insert(iterator position, const Customer* first, const Customer* last) {

	int old_size = _size;
	int interval = last - first;
	int datanum = interval;
	int pos = 0;
	Customer* temp = new Customer[_capacity]{};
	int cur = 0;
	if (arr != NULL) {
		for (int i = 0; i < _size; i++)
			temp[i] = arr[i];


		//delete[] arr; // 힙에러 

	}

	_size += datanum;


	if (_size > _capacity) {
		if (_size < 5) {
			arr = new Customer[_size]{};
			_capacity = _size;
		}
		else {
			arr = new Customer[_size * 2]{};
			_capacity = _size * 2;
		}

		// 뒤로 옮기고
		// const float에 있는 값 나누기 
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



void Vector_Customer::erase(iterator position) {

	int i = 0;

	//for (iterator temp = begin(); temp != end()+1; temp++) {


		//cout << *(temp) ;
		
	//}

	int index = (position - this->begin());

	for (i = index; i < _size - 1; i++) {

		arr[i] = arr[i + 1];
	
	}

	_size--;
	
}

void Vector_Customer::clear() {


	for (int i = 0; i < _size; i++) {

		Customer temp(0, 0, 0);
		arr[i] = temp;

	} 
	_capacity = 0;
	_size = 0;

}

Customer& Vector_Customer::operator[](int index) {

	if (index >= 0 && index < _size) {

		return arr[index];
	}

	
}

const Customer& Vector_Customer::operator[](int index) const {


	if (index >= 0 && index < _size) {

		return arr[index];
	}

	
}

Vector_Customer& Vector_Customer::operator=(const Vector_Customer& v) {

	this->arr = NULL;
	this->_size = v._size;
	this->_capacity = v._capacity;

	this->arr = new Customer[this->_capacity]{};

	for (int i = 0; i < this->_size; i++) {

		arr[i] = v.arr[i];

	}


	return *this;

	

}
