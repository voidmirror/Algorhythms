#ifndef Dynamics_H
#define Dynamics_H

struct List {
	char value;
	List* point;
};

struct doubleList {
	char value;
	doubleList* pointPrev;
	doubleList* pointNext;
};

void add2List(List** head, char addval);
void printList(List* head);

#endif