#include "pch.h"
#include "List.h"

using namespace std;


List::List()
{
	head = NULL;
	tail = NULL;
}

List::~List()
{
	node* n = this->head;
	node* cur = NULL;
	while (n) {
		cur = n;
		n = n->next;
		delete(cur);
	}
	head = NULL;
	tail = NULL;
}

int List::size() {
	node* cur = head;
	int size = 0;
	while (cur != NULL) {
		size++;
		cur = cur->next;
	}
	return size;
}

void List::add(int x) {
	node* temp = new node;
	temp->data = x;
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
		tail = temp;
	}
	else {
		tail->next = temp;
		tail = temp;
	}
	temp = NULL;
}

void List::addHead(int x) {
	node* temp = new node;
	temp->data = x;
	temp->next = head;
	if (head == NULL) {
		tail = temp;
	}
	head = temp;
}
