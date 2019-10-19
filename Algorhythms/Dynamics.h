#ifndef Dynamics_H
#define Dynamics_H

struct List {
	char value;
	List* point;
};

struct doubleList {
	int value;
	doubleList* pointPrev;
	doubleList* pointNext;
};

void add2List(List** head, int addval);
void printList(List* head);

#endif