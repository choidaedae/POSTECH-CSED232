#pragma once

#include<cstdio>
#include<iostream>
#include<fstream>
#include "Rider.h"
#include "Customer.h"
#include "Vector_Rider.h"
#include "Vector_Customer.h"


using namespace std;

class Pizza {


public:

	Pizza();
	Pizza(float money);
	Pizza(const Pizza& pizza);
	~Pizza();
	void setPrice();
	void setPrice(float a, float b);
	void hire(const Rider& Rider);
	void hire(const Rider* riders, int size);
	void enroll(const Customer& customer, bool a);
	void enroll(const Customer* customers, int size, bool a);
	float reportMoney() const;
	int numRiders() const;
	int numCustomers(bool a) const;
	float meanFee() const;
	float meanTimeRiders() const;
	float meanMoneyCustomers() const;
	float meanTimeCustomers() const;
	void deliver();
	friend ostream& operator <<(ostream& os, const Pizza& x); 


private: 

	float money; //피자 가게의 돈 
	float priceA; //customer A에게 받는 피자 가격  
	float priceB; //customer B에게 받는 피자 가격
	float feeA; //customer A에게 받는 배달료 
	float feeB; //customer B에게 받는 배달료 
	float timeA; //A 구역에 배달하는 데 걸리는 시간 
	float timeB; //B 구역에 배달하는 데 걸리는 시간 
	Vector_Customer A; //각 class들을 멤버 변수로 가지고 있음. 
	Vector_Customer B;
	Vector_Rider R;
	
};