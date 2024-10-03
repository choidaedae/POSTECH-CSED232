#include "Customer.h"

Customer::Customer() { //Customer 기본 생성자 

	money = 1000;	
	paidMoney = 0;
	time = 0;
}

Customer::Customer(float money, float paidMoney, float time){ //Customer 생성자 
	//멤버 변수에 대한 매개변수 값 대입 
	this->money = money;
	this->paidMoney = paidMoney;
	this->time = time;
	

}

Customer::Customer(const Customer& customer){ //Customer 복사 생성자 

	//멤버 변수에 대한 값 대입  
	this->money = customer.money;
	this->paidMoney = customer.paidMoney;
	this->time = customer.time;


}

Customer::~Customer(){ //Customer 소멸자 

}

float Customer :: reportMoney() const{ //Customer가 값을 지불하는 함수 

	return paidMoney;

}

float Customer :: reportTime() const{ //Customer가 값을 지불하는 함수 

	return time;

}

void Customer :: pay(float price, float time){ //Customer가 값을 지불하는 함수 

	money -= price;
	paidMoney += price;
	this->time += time;

}

ostream& operator <<(ostream& os, const Customer& x) { // << operator 오버로딩; class 출력할 수 있게 만듦 

	os << "(money, paidMoney, time) :(" << x.money << ", " << x.paidMoney << ", " << x.time << ")" << endl;

	return os;
}




