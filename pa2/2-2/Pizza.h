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

	float money; //���� ������ �� 
	float priceA; //customer A���� �޴� ���� ����  
	float priceB; //customer B���� �޴� ���� ����
	float feeA; //customer A���� �޴� ��޷� 
	float feeB; //customer B���� �޴� ��޷� 
	float timeA; //A ������ ����ϴ� �� �ɸ��� �ð� 
	float timeB; //B ������ ����ϴ� �� �ɸ��� �ð� 
	Vector_Customer A; //�� class���� ��� ������ ������ ����. 
	Vector_Customer B;
	Vector_Rider R;
	
};