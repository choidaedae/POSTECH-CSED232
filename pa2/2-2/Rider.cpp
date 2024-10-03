#include "Rider.h"

Rider::Rider(){ //Rider 기본 생성자 
	money = 0;
	earnMoney = 0;
	time = 0;

}

Rider::Rider(float money, float earnMoney, float time){ //Rider 생성자 
	//멤버 변수에 대한 매개변수 값 대입
	this->money = money;
	this->earnMoney = earnMoney;
	this->time = time;

}

Rider::Rider(const Rider& rider){ //Rider 복사 생성자 

	//멤버 변수에 대한 값 대입  

	this->money = rider.money;
	this->earnMoney = rider.earnMoney;
	this->time = rider.time;
}

Rider::~Rider(){ //Rider 소멸자 

}

float Rider::reportMoney() const{ //Rider가 현재 번 돈을 리턴하는 함수


	return earnMoney;

}

float Rider::reportTime() const{ //Rider가 총 배달한 시간을 리턴하는 함수


	return time;
}

void Rider::deliver(float price, float time){  //Rider의 배달 정보 저장 (배달료만큼 받고, 배달시간 만큼 더해줌 

	this->earnMoney += price;
	this->time += time;
}

ostream& operator <<(ostream& os, const Rider& x) { // << operator 오버로딩; class 출력할 수 있게 만듦 

	os << "(money, earnMoney, time) :(" << x.money << ", " << x.earnMoney << ", " << x.time << ")" << endl;

	return os;
}
