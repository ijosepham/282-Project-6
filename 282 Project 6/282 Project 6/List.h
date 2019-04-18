#pragma once
#include <string>

using namespace std;

struct node {
public:
	int data;
	node* next;
};

class List
{
private:
	node* head;
	node* tail;
public:
	List();

	int size();

	void add(int);
	void addHead(int);
	void addPos(int, int);

	int remove(int);
	int removeHead(int);
	int removePos(int, int);

	void display();
	string to_string();

	~List();
};

