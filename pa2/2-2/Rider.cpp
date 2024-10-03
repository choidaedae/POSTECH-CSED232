#include "Rider.h"

Rider::Rider(){ //Rider �⺻ ������ 
	money = 0;
	earnMoney = 0;
	time = 0;

}

Rider::Rider(float money, float earnMoney, float time){ //Rider ������ 
	//��� ������ ���� �Ű����� �� ����
	this->money = money;
	this->earnMoney = earnMoney;
	this->time = time;

}

Rider::Rider(const Rider& rider){ //Rider ���� ������ 

	//��� ������ ���� �� ����  

	this->money = rider.money;
	this->earnMoney = rider.earnMoney;
	this->time = rider.time;
}

Rider::~Rider(){ //Rider �Ҹ��� 

}

float Rider::reportMoney() const{ //Rider�� ���� �� ���� �����ϴ� �Լ�


	return earnMoney;

}

float Rider::reportTime() const{ //Rider�� �� ����� �ð��� �����ϴ� �Լ�


	return time;
}

void Rider::deliver(float price, float time){  //Rider�� ��� ���� ���� (��޷Ḹŭ �ް�, ��޽ð� ��ŭ ������ 

	this->earnMoney += price;
	this->time += time;
}

ostream& operator <<(ostream& os, const Rider& x) { // << operator �����ε�; class ����� �� �ְ� ���� 

	os << "(money, earnMoney, time) :(" << x.money << ", " << x.earnMoney << ", " << x.time << ")" << endl;

	return os;
}
