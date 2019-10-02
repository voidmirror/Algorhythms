#include <iostream>
#include "Dynamics.h"

using namespace std;

void add2List(List** head, char addval) {
	List **pp = head;
	List *newelem;
	while (*pp) {
		if (addval < (*head)->value)
			break;
		else
			pp = &((*pp)->point);
	}
	newelem = (List*)malloc(sizeof(List));
	newelem->value = addval;
	newelem->point = *pp;
	*pp = newelem;
}

void printList(List* head) {
	List* p = head;
	while (p) {
		cout << p->value << " ";
		p = p->point;
	}
	cout << endl;
}

void add2DoubleList(doubleList** head, char addval) {
	doubleList **pp = head;
	doubleList *newelem;
	while (*pp) {
		if (addval < (*head)->value)
			break;
		else
			pp = &((*pp)->pointNext);
	}
	newelem = (doubleList*)malloc(sizeof(doubleList));
	newelem->value = addval;
	newelem->pointNext = *pp;
	newelem->pointPrev = (*pp)->pointPrev;
	*pp = newelem;
}