#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// 사용자 정의 자료형

typedef struct node{ 

	int data;
	node* next;

}NODE;

typedef struct queue{

	int count;
	NODE* front; 
	NODE* rear;

}QUEUE; 

//함수 

int search(int des_row, int des_col, int map[][11], int visit[][11], QUEUE qrow, QUEUE qcol, QUEUE qcnt);
int enqueue(QUEUE* q, int data);
int dequeue(QUEUE* q);
int isEmpty(QUEUE* q);
int check(int row, int col, int map[][11], int visit[][11]);
void clean(int arrr[][11]);
void cleanq(QUEUE* q);

int main() {

	char arr[11][11] = { 0 }; // map 정보를 일시적으로 char로 가져오는 배열 
	int map[11][11] = { 0 }; // map 정보를 저장하는 배열 
	int visit[11][11] = { 0 }; // 방문 여부를 나타내는 배열 
	ifstream fin("input.txt"); // 입출력 파일 열어줌 
	ofstream fout("output.txt");
	int key_row, key_col, exit_row, exit_col; // 키와 출구의 행과 열 정보 저장함. 
	int dis_key = 0; int dis_exit = 0; int dis_tot = 0; // 출발지 - 키까지의 거리 / 키 - 탈출구 까지의 거리 / 2개를 더하면 답임. 
	QUEUE qrow; QUEUE qcol; QUEUE qcnt;  // 행과 열, 거리에 대한 큐 선언 및 초기화
	qrow.count = 0; qrow.front = NULL; qrow.rear = NULL;
	qcol.count = 0; qcol.front = NULL; qcol.rear = NULL;
	qcnt.count = 0; qcnt.front = NULL; qcnt.rear = NULL;

	for (int i = 0; i < 10; i++) { // data를 입력하는 과정, k와 e를 받기 위해 우선 char형 배열에 넣어줌 

		for (int j = 0; j < 10; j++) {
			fin >> arr[i][j];
			if (arr[i][j] == 'k') { // key의 행과 열 정보 저장
				key_row = i;
				key_col = j;
			}
			if (arr[i][j] == 'e') {  // exit의 행과 열 정보 저장
				exit_row = i;
				exit_col = j;
			}
		}
	}

	for (int i = 0; i < 10; i++) { //char 형 배열 arr을 int형 배열 map에 일대일 대응하는 과정 (연산을 위해 int형 배열에 넣는 것이 유리함)

		for (int j = 0; j < 10; j++) {

			if (arr[i][j] == '1') map[i][j] = 1;
			if (arr[i][j] == '0') map[i][j] = 0;
			if (arr[i][j] == 'k') map[i][j] = -1; // k와 e는 가독성을 위해 -1로 처리함. 
			if (arr[i][j] == 'e') map[i][j] = -1;
	
		}

	}

	enqueue(&qrow, 0); enqueue(&qcol, 0); enqueue(&qcnt, 0); //초기 값 넣어줌. (0,0)에서 시작하고 거리값도 0 
	dis_key = search(key_row, key_col, map, visit, qrow, qcol, qcnt); //key까지의 거리는 (0,0)에서 (key_row, key_col 까지 BFS를 했을 때 나오는 거리값

	clean(visit); cleanq(&qrow); cleanq(&qcol); cleanq(&qcnt); // visit 배열과 각 큐들을 초기화해줌. 

	enqueue(&qrow, key_row); enqueue(&qcol, key_col); enqueue(&qcnt, 0); //초기 값 넣어줌. (key_row, key_col)에서 시작하고 거리값도 0
	dis_exit = search(exit_row, exit_col, map, visit, qrow, qcol, qcnt); //key부터 exit까지의 거리는 (key_row, key_col)에서 (exit_row, exit_col)까지 BFS를 했을 때 나오는 거리값

	dis_tot = dis_key + dis_exit; // 출력할 답은 2개를 더해주면 됨. 

	fout << dis_tot; //out.txt에 출력해줌 

	fin.close();
	fout.close();

	return 0;

}

int check(int row, int col, int map[][11], int visit[][11]) { //출발점 – key에 대해 1번, key – exit에 대해 1번, 총 2번의 반복 실행을 거치기 때문에 2번째 실행 직전에 visit array를 비워주기 위해 만든 함수이다. 

	if (row < 0 || row > 10 || col < 0 || col >10) return 0; // 올바른 index여야 함 
	if (map[row][col] == 1) return 0; //그 칸이'길'이어야 함. 
	if (visit[row][col] == 1) return 0; // 방문하지 않았던 칸이어야 함 

	return 1;

}


int search(int des_row, int des_col, int map[][11], int visit[][11], QUEUE qrow, QUEUE qcol, QUEUE qcnt) {
	
	//이번 과제에서 가장 비중이 큰 함수로, 목적지의 row와 col 값을 매개변수로 가져가고 BFS 알고리즘을 통해 출발지와 목적지까지의 최단거리를 return하는 함수이다. 

	int cnt = 0; 

	while (1) { // while문 안에서 break시킴 

		int cur_row = qrow.front->data; dequeue(&qrow); //front 값을 받아오고 dequeue
		int cur_col = qcol.front->data; dequeue(&qcol); //front 값을 받아오고 dequeue
		int c = qcnt.front->data; dequeue(&qcnt); //front 값을 받아오고 dequeue

		if (visit[cur_row][cur_col] == 1) continue; //이미 방문한 곳이면 다음 칸을 탐색
		visit[cur_row][cur_col] = 1;

		if (des_row == cur_row && des_col == cur_col) { // 목적지의 행, 열 index와 현재 행,열 index가 일치하면 반복문 밖을 빠져나간 뒤 search함수를 return함. 
			cnt = c;
			break;
		}

		if (check(cur_row, cur_col + 1, map, visit)==1){ // 오른쪽으로 갈 수 있는 경우  
		
			enqueue(&qcol, cur_col + 1); 
			enqueue(&qrow, cur_row);
			enqueue(&qcnt, c + 1); // cnt값을 하나 증가 
		}
		if (check(cur_row, cur_col - 1, map, visit)==1) { // 왼쪽으로 갈 수 있는 경우 
		
			enqueue(&qcol, cur_col - 1);
			enqueue(&qrow, cur_row);
			enqueue(&qcnt, c + 1);
		}
		if (check(cur_row + 1, cur_col, map, visit)==1) { // 아래로 갈 수 있는 경우 
		
			enqueue(&qrow, cur_row + 1);
			enqueue(&qcol, cur_col);
			enqueue(&qcnt, c + 1);
		}
		if (check(cur_row - 1, cur_col, map, visit)==1) { // 위로 갈 수 있는 경우 
		
			enqueue(&qrow, cur_row - 1);
			enqueue(&qcol, cur_col);
			enqueue(&qcnt, c + 1);
		}
	}

	return cnt; //cnt = 거리값 
	
}

void clean(int arr[][11]) { //배열을 0으로 초기화해주는 함수 

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j] = 0;
		}
	}
}

void cleanq(QUEUE* q) { //큐를 비워주는 함수 

	while (!isEmpty(q)) dequeue(q);
}


int enqueue(QUEUE* q, int data) //FIFO 방식인 queue의 rear에 node를 삽입해주는 함수이다. 
{
	NODE* temp = new NODE;


	if (!temp) 
		return 0;

	temp->data = data;
	temp->next = NULL;


	if (isEmpty(q))
	{
		q->front = temp;
		q->rear = temp;
		q->count++;

	}
	else
	{
		q->rear->next = temp;
		q->rear = temp;
		q->count++;
	}


	return 1;
} 

int	dequeue(QUEUE* q) //queue의 front에 위치한 node를 떼주는 함수이다. 
{
	NODE* temp = new NODE;

	if (isEmpty(q)) return 0; // 큐가 비어 있는 경우
		
	temp = q->front;
	q->front = q->front->next;
	q->count--;

	
	return 1;
}

int isEmpty(QUEUE* q) // queue가 비어 있는지 확인하는 함수이다. 
{
	return q->front == NULL;
}