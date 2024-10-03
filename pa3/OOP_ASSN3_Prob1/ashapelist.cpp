#include "ashapelist.h"
#include<iostream>

using namespace std;

AShapeList::AShapeList() { // �⺻ ������ 
    
    AShapeNode* hlist = new AShapeNode; // dummy head node�� ������ 
    hlist->next = NULL; // head node �ʱ�ȭ 
    hlist->shape = NULL;
    head = hlist; 
    tail = hlist;
    size = 0;


}

AShapeList::~AShapeList() { // �Ҹ��� 

    
    int oldsize = size; // popnodeByIdx�� ȣ�����ָ� size�� �پ��� ������ ���� ����� ���� 
    for (int i = 0; i < oldsize; i++) {
        delete popNodeByIdx(0); // ����Ʈ ���ʴ�� �����Ҵ� ���� (�տ������� �����ֹǷ� 0�� �ε����� ��� delete ���ָ� ��.)
    }

    delete head; //dummy head node �����Ҵ� ���� 


}

void AShapeList::addNewAShape(AShape* new_shape) { // ���ο� ������ ����Ʈ �� �ڿ� �����ϴ� �Լ� 

    AShapeNode* node = new AShapeNode; //node�� ���� �־��� 
    node->next = NULL;
    node->shape = new_shape;

    if (head->next == NULL) { // �� ����Ʈ�� ���� 

        head->next = node;
        tail = node;
    }

    else { // �� �ִ� ����Ʈ�� ���� 


        AShapeNode* temp = head->next; // ���� ù ��带 ����Ŵ 

        for (int i = 0; i < size - 1; i++) { //�� ������ ���� 

            temp = temp->next;

        }

        temp->next = node; //�ٲ� �� tail�� ����Ű�� ��. 
        tail = node;

    }

    size++; // size 1 �÷��� 
}


AShapeNode* AShapeList::popNodeByIdx(int idx) {


    AShapeNode* Pre = head; // ���� ���� ��带 ����Ű�� ������ 
    AShapeNode* temp = head->next; // ���� ��� ��带 ����Ű�� ������, ù ��带 ����Ű�� �ʱ�ȭ�� 

    if (temp->next == NULL) { // node 1���� ����Ʈ���� ���� 
  

        head->next = NULL; // ����� 
        tail = NULL; // ������ �����ϴ� ����� 
    }

    else { // node 2�� �̻��� ����Ʈ���� ���� 

        for (int i = 0; i < idx; i++) { // zero - based index�̹Ƿ� index����ŭ �������ָ� ��. 

            Pre = temp; 
            temp = temp->next; 

        }

        Pre->next = temp->next; // ���� ����� ���� ����Ʈ �ٽ� �̾���.

    }

    size--;


    return temp; // ���� ��� ��带 ������ 


}

const AShapeNode* AShapeList::getNodeByIdx(int idx) const { //idx��° ��带 ����Ű�� �ϴ� �Լ� 

    if (idx == 0) return head->next; 


    AShapeNode* temp = head->next;

    for (int i = 0; i < idx; i++) { // idx-1ȸ��ŭ �������� �� 

        temp = temp->next; // n��° node ���� 

    }

    return temp;
}


void AShapeList::displayAShapeList() const {

    cout << "[=========List of AShape======]" << endl;
    cout << "Current Size: " << size << endl;

    AShapeNode* temp = head->next;


    for (int i = 0; i < size; i++) {
        cout << i << ") ";
        temp->shape->print(); // virtual �Լ��� ��� 
        temp = temp->next;
    }

}

void AShapeList::drawAll(WhiteBoard* board) const {

    AShapeNode* temp = head->next;

    for (int i = 0; i < size; i++) {

        temp->shape->draw(board); // virtual �Լ��� �׷���
        temp = temp->next;

    }
    
}


int AShapeList::getsize() const {

    return size;

}