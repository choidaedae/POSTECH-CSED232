#pragma once
#include "whiteboard.h"
class AShape 
{

protected:

	char alphabet;

public:

	AShape();
	virtual ~AShape();
	virtual void draw(WhiteBoard* board) const = 0;
	virtual void print() const = 0;
	virtual int size() const = 0;

};


class APoint :public AShape
{

private:

	int x;
	int y;

public:

	APoint();
	APoint(int x_, int y_, char alphabet_);
	~APoint();
	void draw(WhiteBoard* board) const;
	void print() const;
	int size() const;

};

class AVerticalLine :public AShape 
{

private:

	int x;
	int y_start;
	int y_end;

public:
	AVerticalLine();
	AVerticalLine(int x_, int y_start_, int y_end_, char alphabet_);
	~AVerticalLine();
	void draw(WhiteBoard* board) const;
	void print() const;
	int size() const;

};

class AHorizontalLine :public AShape 
{

private:

	int x_start;
	int x_end;
	int y;

public:

	AHorizontalLine();
	AHorizontalLine(int y_, int x_start_, int x_end_, char alphabet_);
	~AHorizontalLine();
	void draw(WhiteBoard* board) const;
	void print() const;
	int size() const;

};

class ARectangle :public AShape 
{

private:

	int x_start;
	int y_start;
	int x_end;
	int y_end;

public:

	ARectangle();
	ARectangle(int x_start_, int y_start_, int x_end_, int y_end_, char alphabet_);
	~ARectangle();
	void draw(WhiteBoard* board) const;
	void print() const;
	int size() const;

};