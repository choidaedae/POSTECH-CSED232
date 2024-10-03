#pragma once
#include "ashape.h"

struct AShapeNode {

	AShape* shape;
	AShapeNode* next;
};

class AShapeList {

private:

	AShapeNode* head;
	AShapeNode* tail;
	int size;

public:

	AShapeList();
	~AShapeList();
	void addNewAShape(AShape* new_shape);
	AShapeNode* popNodeByIdx(int idx);
	const AShapeNode* getNodeByIdx(int idx) const;
	void displayAShapeList() const;
	void drawAll(WhiteBoard* board) const;
	int getsize() const;


};