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

//void add2DoubleList(doubleList** head, char addval) {
//	doubleList **pp = head;
//	doubleList *newelem;
//	while (*pp) {
//		if (addval < (*head)->value)
//			break;
//		else
//			pp = &((*pp)->pointNext);
//	}
//	newelem = (doubleList*)malloc(sizeof(doubleList));
//	newelem->value = addval;
//	newelem->pointNext = *pp;
//	newelem->pointPrev = (*pp)->pointPrev;
//	*pp = newelem;
//}

void add2DoubleList(doubleList** head, doubleList** tail, int addval) {
	doubleList **pp = tail;
	doubleList *newelem;

	newelem->value = addval;
	newelem->pointNext = NULL;

	if (!(*head)) {
		newelem->pointPrev = NULL;
		*head = newelem;
		*tail = newelem;
	}
	else {
		newelem->pointPrev = *pp;
		(*pp)->pointNext = newelem;
		*pp = newelem;
	}
}

List** createSkipListArr(int lvls, List *head) {
	// lvls - number of levels

	List **lvlarr = (List**)malloc(lvls * sizeof(List*));
	for (int i = 0; i < lvls; i++) {
		lvlarr[i] = NULL;
		//*(lvlarr + i) = NULL;
	}
	lvlarr[0] = head;

	int randomize;
	List *elem = head, *listelem = NULL;
	for (int i = 1; i < lvls; i++) {
		while (elem) {
			randomize = rand() % 2;
			if (randomize) {
				List *newelem;
				newelem = (List*)malloc(sizeof(List));
				newelem->point = NULL;
				newelem->value = elem->value;

			}
		}
	}
}