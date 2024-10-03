#include "Pizza.h"

Pizza::Pizza() { // �⺻ ������

	money = 10000; 
	timeA = 10;
	timeB = 20;

	for (int i = 0; i < 5; i++) {
		//A,B,R �� ���� size ���� �����ڷ� ��������. 
		A = Vector_Customer(5); 
		B = Vector_Customer(5);
		R = Vector_Rider(5);

	}
	
	Pizza::setPrice();
}

Pizza::Pizza(float money){ //money ������ �����ͼ� �����ϴ� ������ 


	this->money = money; // this �����͸� ����ؼ� ������� 
	timeA = 10;
	timeB = 20;
	//A,B,R �� ���� size ���� �����ڷ� ��������. 
	A = Vector_Customer(5);
	B = Vector_Customer(5);
	R = Vector_Rider(5);

	Pizza::setPrice();


}

Pizza::Pizza(const Pizza& pizza) { // ���� ������ 


	money = pizza.money; // ��� �����鿡 ���� ���� ���� 
	priceA = pizza.priceA;
	priceB = pizza.priceB;
	feeA = pizza.feeA;
	feeB = pizza.feeB;
	timeA = pizza.timeA;
	timeB = pizza.timeB;

	A = pizza.A; //class �� ���Կ����� ����
	B = pizza.B;
	R = pizza.R;
	

}

Pizza::~Pizza(){ // �Ҹ��� 

}

void Pizza::setPrice(){ //���� ���� �Լ� 

	priceA = 100 - 3 * (float) A.size();  //* A���� 
	priceB = 100 - 6 * (float)B.size();  //* B���� 
	feeA = 10 - (float)A.size(); 
	feeB = 10 - (float)B.size();


}

void Pizza::setPrice(float a, float b){ // ���� ��� a, b�� �����ͼ� �������ִ� ���� ���� �Լ� 

	priceA = 100 - a * (float)A.size();  //* A���� 
	priceB = 100 - b * (float)B.size();  //* B���� 
	feeA = 10 - (float)A.size();
	feeB = 10 - (float)B.size();

	


}


void Pizza::hire(const Rider& rider) { // rider�� ����ϴ� �Լ� (���Լ���)

	R.erase(R.begin()); //erase �Լ� ȣ��� �� ������ ���� 

	R.push_back(rider); //push_back �Լ� ȣ��� �� �ڿ� �־��� 
}

void Pizza::hire(const Rider* riders, int size){ // rider�� ����ϴ� �Լ� (rider �迭�� �鿩��, ���Լ���)

	for (int i = 0; i < size; i++) {

		R.erase(R.begin());  //erase �Լ� ȣ��� �տ������� size��ŭ ������ ���� 
		
	}

	R.insert(R.begin(), riders, riders + size);	 //insert �迭�� �Լ��� Rider �迭 ����


}

void Pizza::enroll(const Customer& customer, bool a){ //Ư�� ������ ���� �߰��ϴ� �Լ� (���Լ���)

	if (a == true) {

		B.erase(B.begin()); //B�� �� �� �� ����� 
		A.push_back(customer); //A�� �� �ڿ� �־��� 
		
	}

	else { 

		A.erase(A.begin()); //A�� �� �� �� �����
		B.push_back(customer); //B�� �� �ڿ� �־��� 
		
	}

	setPrice();
}

void Pizza::enroll(const Customer* customers, int size, bool a){  //Ư�� ������ �� �迭�� �߰��ϴ� �Լ� (���Լ���)


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

float Pizza::reportMoney() const{ //���� ���԰� ���� ������ �ִ� ���� �����Ѵ�.


	return money;

}

int Pizza::numRiders() const{ //���� Rider ���� �������� �Լ� 

	return R.size();
}

int Pizza::numCustomers(bool a) const{ //���� Customer ���� �������� �Լ� 


	if (a == true) return A.size();
	
	else return B.size();

}

float Pizza::meanFee() const{ // ���� ��� ���� ���̴��� ����� ���� �� ���� ����� �����Ѵ�.


	float acc = 0;//���� ���� �����ϴ� ���� 
	for (int i = 0; i < R.size(); i++) {

		acc += R[i].reportMoney();


	}

	return acc / R.size();
	
}

float Pizza::meanTimeRiders() const {// ���� ��� ���� ���̴��� ����ϴµ� �ɸ� �ð��� ����� �����Ѵ�.

	float acc = 0; //���� ���� �����ϴ� ���� 
	for (int i = 0; i < R.size(); i++) {

		acc += R[i].reportTime();

	}

	return acc / R.size();


}

float Pizza::meanMoneyCustomers() const{ // ���� ���� ���� ������ ���ڸ� �����ϴµ� �� ����� ����� �����Ѵ�.


	float acc = 0; //���� ���� �����ϴ� ���� 

	for (int i = 0; i < A.size(); i++) {
		acc += A[i].reportMoney();

		
	}

	for (int i = 0; i < B.size(); i++) {
		acc += B[i].reportMoney();
	}

	return acc / (A.size()+B.size()); // A._size�� B._size�� ���� �׻� 10�� 

}

float Pizza::meanTimeCustomers() const{ // ���� ���� ���� ������ ���ڸ� �޴µ� �ҿ�� �ð��� ����� �����Ѵ�.


	float acc = 0; //���� ���� �����ϴ� ���� 

	for (int i = 0; i < A.size(); i++) {
		acc += A[i].reportTime();

	}

	for (int i = 0; i < B.size(); i++) {
		acc += B[i].reportTime();

	}


	return acc / (A.size() + B.size()); //a.size+b.size �� �׻� 10�� 


}

void Pizza::deliver() {

	int order = 0;
	int del_order = 0;

	for (int i = 0; i < A.size(); i++) { // A �迭�� ������� ��� 

		del_order = order % 5; // ��޿��� ���� ���� 

		A[i].pay(priceA, timeA);  //pay�Լ� ȣ�� //���ڰ� ����)
		R[del_order].deliver(feeA, timeA); // deliver �Լ��� �������. 
		money += priceA; //������ ���� ���� ������ �����ְ�, ��޷�� ����  
		money -= feeA;

		order++;

	}



	for (int i = 0; i < B.size(); i++) { // B �迭�� ������� ��� 

		del_order = order % 5; // ��޿��� ���� ���� 

		B[i].pay(priceB, timeB); //pay�Լ� ȣ�� (���ڰ� ����)

		R[del_order].deliver(feeB, timeB); // deliver �Լ��� �������.

		money += priceB; //������ ���� ���� ������ �����ְ�, ��޷�� ����  
		money -= feeB;

		order++;

	}
}

ostream& operator <<(ostream& os, const Pizza& x) { // �ܼ�â ����� << ������ �����ε��� ���� ������ 

	
	os << "1) Money : "<< x.money << endl;
	os << "2) (Customer, Price, Fee)" << endl;
	os << "- A : (" << x.A.size() << ", " << x.priceA << ", " << x.feeA << ")" << endl;
	os << "- B : (" << x.B.size() << ", " << x.priceB << ", " << x.feeB << ")" << endl;
	os << "3) Riders : " << x.R.size() << endl;

	
	return os;
}


