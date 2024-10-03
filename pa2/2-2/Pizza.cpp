#include "Pizza.h"

Pizza::Pizza() { // 기본 생성자

	money = 10000; 
	timeA = 10;
	timeB = 20;

	for (int i = 0; i < 5; i++) {
		//A,B,R 에 대해 size 지정 생성자로 생성해줌. 
		A = Vector_Customer(5); 
		B = Vector_Customer(5);
		R = Vector_Rider(5);

	}
	
	Pizza::setPrice();
}

Pizza::Pizza(float money){ //money 변수를 가져와서 생성하는 생성자 


	this->money = money; // this 포인터를 사용해서 명시해줌 
	timeA = 10;
	timeB = 20;
	//A,B,R 에 대해 size 지정 생성자로 생성해줌. 
	A = Vector_Customer(5);
	B = Vector_Customer(5);
	R = Vector_Rider(5);

	Pizza::setPrice();


}

Pizza::Pizza(const Pizza& pizza) { // 복사 생성자 


	money = pizza.money; // 멤버 변수들에 대한 대입 연산 
	priceA = pizza.priceA;
	priceB = pizza.priceB;
	feeA = pizza.feeA;
	feeB = pizza.feeB;
	timeA = pizza.timeA;
	timeB = pizza.timeB;

	A = pizza.A; //class 간 대입연산자 가능
	B = pizza.B;
	R = pizza.R;
	

}

Pizza::~Pizza(){ // 소멸자 

}

void Pizza::setPrice(){ //가격 지정 함수 

	priceA = 100 - 3 * (float) A.size();  //* A고객수 
	priceB = 100 - 6 * (float)B.size();  //* B고객수 
	feeA = 10 - (float)A.size(); 
	feeB = 10 - (float)B.size();


}

void Pizza::setPrice(float a, float b){ // 가격 계수 a, b를 가져와서 지정해주는 가격 지정 함수 

	priceA = 100 - a * (float)A.size();  //* A고객수 
	priceB = 100 - b * (float)B.size();  //* B고객수 
	feeA = 10 - (float)A.size();
	feeB = 10 - (float)B.size();

	


}


void Pizza::hire(const Rider& rider) { // rider를 고용하는 함수 (선입선출)

	R.erase(R.begin()); //erase 함수 호출로 앞 데이터 삭제 

	R.push_back(rider); //push_back 함수 호출로 맨 뒤에 넣어줌 
}

void Pizza::hire(const Rider* riders, int size){ // rider를 고용하는 함수 (rider 배열을 들여옴, 선입선출)

	for (int i = 0; i < size; i++) {

		R.erase(R.begin());  //erase 함수 호출로 앞에서부터 size만큼 데이터 삭제 
		
	}

	R.insert(R.begin(), riders, riders + size);	 //insert 배열로 함수로 Rider 배열 삽입


}

void Pizza::enroll(const Customer& customer, bool a){ //특정 지역에 고객을 추가하는 함수 (선입선출)

	if (a == true) {

		B.erase(B.begin()); //B는 맨 앞 값 지우고 
		A.push_back(customer); //A는 맨 뒤에 넣어줌 
		
	}

	else { 

		A.erase(A.begin()); //A는 맨 앞 값 지우고
		B.push_back(customer); //B는 맨 뒤에 넣어줌 
		
	}

	setPrice();
}

void Pizza::enroll(const Customer* customers, int size, bool a){  //특정 지역에 고객 배열을 추가하는 함수 (선입선출)


	if (a == true) {

		A.insert(A.end(), customers, customers + size);

		
		for (int i = 0; i < size; i++) {

			B.erase(B.begin());
		
		}

	}

	else {

		B.insert(B.end(), customers, customers + size);

		for (int i = 0; i < size; i++) {

			A.erase(A.begin());
	
		}
		
	}

	setPrice();

	return;
}

float Pizza::reportMoney() const{ //피자 가게가 현재 가지고 있는 돈을 리턴한다.


	return money;

}

int Pizza::numRiders() const{ //현재 Rider 수를 가져오는 함수 

	return R.size();
}

int Pizza::numCustomers(bool a) const{ //현재 Customer 수를 가져오는 함수 


	if (a == true) return A.size();
	
	else return B.size();

}

float Pizza::meanFee() const{ // 현재 고용 중인 라이더가 배달을 통해 번 돈의 평균을 리턴한다.


	float acc = 0;//누적 합을 저장하는 변수 
	for (int i = 0; i < R.size(); i++) {

		acc += R[i].reportMoney();


	}

	return acc / R.size();
	
}

float Pizza::meanTimeRiders() const {// 현재 고용 중인 라이더가 배달하는데 걸린 시간의 평균을 리턴한다.

	float acc = 0; //누적 합을 저장하는 변수 
	for (int i = 0; i < R.size(); i++) {

		acc += R[i].reportTime();

	}

	return acc / R.size();


}

float Pizza::meanMoneyCustomers() const{ // 현재 관리 중인 고객들이 피자를 구매하는데 든 비용의 평균을 리턴한다.


	float acc = 0; //누적 합을 저장하는 변수 

	for (int i = 0; i < A.size(); i++) {
		acc += A[i].reportMoney();

		
	}

	for (int i = 0; i < B.size(); i++) {
		acc += B[i].reportMoney();
	}

	return acc / (A.size()+B.size()); // A._size와 B._size의 합은 항상 10임 

}

float Pizza::meanTimeCustomers() const{ // 현재 관리 중인 고객들이 피자를 받는데 소요된 시간의 평균을 리턴한다.


	float acc = 0; //누적 합을 저장하는 변수 

	for (int i = 0; i < A.size(); i++) {
		acc += A[i].reportTime();

	}

	for (int i = 0; i < B.size(); i++) {
		acc += B[i].reportTime();

	}


	return acc / (A.size() + B.size()); //a.size+b.size 는 항상 10임 


}

void Pizza::deliver() {

	int order = 0;
	int del_order = 0;

	for (int i = 0; i < A.size(); i++) { // A 배열에 순서대로 배달 

		del_order = order % 5; // 배달원의 순서 지정 

		A[i].pay(priceA, timeA);  //pay함수 호출 //피자값 지불)
		R[del_order].deliver(feeA, timeA); // deliver 함수로 배달해줌. 
		money += priceA; //가게의 돈에 피자 가격을 더해주고, 배달료는 빼줌  
		money -= feeA;

		order++;

	}



	for (int i = 0; i < B.size(); i++) { // B 배열에 순서대로 배달 

		del_order = order % 5; // 배달원의 순서 지정 

		B[i].pay(priceB, timeB); //pay함수 호출 (피자값 지불)

		R[del_order].deliver(feeB, timeB); // deliver 함수로 배달해줌.

		money += priceB; //가게의 돈에 피자 가격을 더해주고, 배달료는 빼줌  
		money -= feeB;

		order++;

	}
}

ostream& operator <<(ostream& os, const Pizza& x) { // 콘솔창 출력을 << 연산자 오버로딩을 통해 구현함 

	
	os << "1) Money : "<< x.money << endl;
	os << "2) (Customer, Price, Fee)" << endl;
	os << "- A : (" << x.A.size() << ", " << x.priceA << ", " << x.feeA << ")" << endl;
	os << "- B : (" << x.B.size() << ", " << x.priceB << ", " << x.feeB << ")" << endl;
	os << "3) Riders : " << x.R.size() << endl;

	
	return os;
}


