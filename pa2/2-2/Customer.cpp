#include "Customer.h"

Customer::Customer() { //Customer �⺻ ������ 

	money = 1000;	
	paidMoney = 0;
	time = 0;
}

Customer::Customer(float money, float paidMoney, float time){ //Customer ������ 
	//��� ������ ���� �Ű����� �� ���� 
	this->money = money;
	this->paidMoney = paidMoney;
	this->time = time;
	

}

Customer::Customer(const Customer& customer){ //Customer ���� ������ 

	//��� ������ ���� �� ����  
	this->money = customer.money;
	this->paidMoney = customer.paidMoney;
	this->time = customer.time;


}

Customer::~Customer(){ //Customer �Ҹ��� 

}

float Customer :: reportMoney() const{ //Customer�� ���� �����ϴ� �Լ� 

	return paidMoney;

}

float Customer :: reportTime() const{ //Customer�� ���� �����ϴ� �Լ� 

	return time;

}

void Customer :: pay(float price, float time){ //Customer�� ���� �����ϴ� �Լ� 

	money -= price;
	paidMoney += price;
	this->time += time;

}

ostream& operator <<(ostream& os, const Customer& x) { // << operator �����ε�; class ����� �� �ְ� ���� 

	os << "(money, paidMoney, time) :(" << x.money << ", " << x.paidMoney << ", " << x.time << ")" << endl;

	return os;
}




