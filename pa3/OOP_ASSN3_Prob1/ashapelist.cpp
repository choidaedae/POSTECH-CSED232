#include "ashapelist.h"
#include<iostream>

using namespace std;

AShapeList::AShapeList() { // 기본 생성자 
    
    AShapeNode* hlist = new AShapeNode; // dummy head node를 구현함 
    hlist->next = NULL; // head node 초기화 
    hlist->shape = NULL;
    head = hlist; 
    tail = hlist;
    size = 0;


}

AShapeList::~AShapeList() { // 소멸자 

    
    int oldsize = size; // popnodeByIdx를 호출해주면 size가 줄어들기 때문에 이전 사이즈를 저장 
    for (int i = 0; i < oldsize; i++) {
        delete popNodeByIdx(0); // 리스트 차례대로 동적할당 해제 (앞에서부터 없애주므로 0번 인덱스를 계속 delete 해주면 됨.)
    }

    delete head; //dummy head node 동적할당 해제 


}

void AShapeList::addNewAShape(AShape* new_shape) { // 새로운 도형을 리스트 맨 뒤에 삽입하는 함수 

    AShapeNode* node = new AShapeNode; //node에 정보 넣어줌 
    node->next = NULL;
    node->shape = new_shape;

    if (head->next == NULL) { // 빈 리스트에 삽입 

        head->next = node;
        tail = node;
    }

    else { // 차 있는 리스트에 삽입 


        AShapeNode* temp = head->next; // 가장 첫 노드를 가리킴 

        for (int i = 0; i < size - 1; i++) { //끝 노드까지 접근 

            temp = temp->next;

        }

        temp->next = node; //바꾼 뒤 tail이 가리키게 함. 
        tail = node;

    }

    size++; // size 1 늘려줌 
}


AShapeNode* AShapeList::popNodeByIdx(int idx) {


    AShapeNode* Pre = head; // 삭제 이전 노드를 가리키는 포인터 
    AShapeNode* temp = head->next; // 삭제 대상 노드를 가리키는 포인터, 첫 노드를 가리키게 초기화함 

    if (temp->next == NULL) { // node 1개인 리스트에서 삭제 
  

        head->next = NULL; // 비워줌 
        tail = NULL; // 꼬리를 참조하는 경우임 
    }

    else { // node 2개 이상인 리스트에서 삭제 

        for (int i = 0; i < idx; i++) { // zero - based index이므로 index값만큼 움직여주면 됨. 

            Pre = temp; 
            temp = temp->next; 

        }

        Pre->next = temp->next; // 삭제 대상을 빼고 리스트 다시 이어줌.

    }

    size--;


    return temp; // 삭제 대상 노드를 리턴함 


}

const AShapeNode* AShapeList::getNodeByIdx(int idx) const { //idx번째 노드를 가리키게 하는 함수 

    if (idx == 0) return head->next; 


    AShapeNode* temp = head->next;

    for (int i = 0; i < idx; i++) { // idx-1회만큼 움직여야 함 

        temp = temp->next; // n번째 node 리턴 

    }

    return temp;
}


void AShapeList::displayAShapeList() const {

    cout << "[=========List of AShape======]" << endl;
    cout << "Current Size: " << size << endl;

    AShapeNode* temp = head->next;


    for (int i = 0; i < size; i++) {
        cout << i << ") ";
        temp->shape->print(); // virtual 함수로 출력 
        temp = temp->next;
    }

}

void AShapeList::drawAll(WhiteBoard* board) const {

    AShapeNode* temp = head->next;

    for (int i = 0; i < size; i++) {

        temp->shape->draw(board); // virtual 함수로 그려줌
        temp = temp->next;

    }
    
}


int AShapeList::getsize() const {

    return size;

}