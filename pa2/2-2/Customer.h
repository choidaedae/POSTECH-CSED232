#pragma once


#include<cstdio>
#include<iostream>
#include<fstream>

using namespace std;

class Customer {

public:

	Customer();

	Customer(float money, float paidMoney, float time);

	Customer(const Customer& customer);

	~Customer();

	float reportMoney() const;

	float reportTime() const;

	void pay(float price, float time);

	friend ostream& operator <<(ostream& os, const Customer& x);


private:

	float money; // customer�� ���� ������ �ִ� ��

	float paidMoney; // customer�� ������ ��

	float time; // custtomer�� ��ٸ� �ð� 

};