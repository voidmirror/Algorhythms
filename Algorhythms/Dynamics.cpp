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

	newelem = (doubleList*)malloc(sizeof(doubleList));
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

Skip** createSkipListArr(int lvls, Skip *head, int* checkArrLengthP) {
	// lvls - number of levels

	Skip **lvlarr = (Skip**)malloc(lvls * sizeof(Skip*));
	for (int i = 0; i < lvls; i++) {
		lvlarr[i] = NULL;
		//*(lvlarr + i) = NULL;
	}
	lvlarr[0] = head;

	int randomize;
	Skip *elem = head, *listelem = NULL;
	for (int i = 1; i < lvls; i++) {
		while (elem) {
			randomize = rand() % 2;
			if (randomize) {
				Skip *newelem;
				newelem = (Skip*)malloc(sizeof(Skip));
				newelem->point = NULL;
				newelem->value = elem->value;
				newelem->lowlvl = elem;
				if (listelem) {
					listelem->point = newelem;
					listelem = listelem->point;
				}
				else {
					lvlarr[i] = newelem;
					//*(lvlarr + i) = newelem;
					listelem = newelem;
					(*checkArrLengthP)++;
				}
			}
			elem = elem->point;
		}
		elem = lvlarr[i];
		listelem = NULL;
	}
	return lvlarr;
}

void fillSkipList(Skip** head, int addval) {
	Skip **pp = head;
	Skip *newelem;
	while (*pp) {
		if (addval < (*head)->value)
			break;
		else
			pp = &((*pp)->point);
	}
	newelem = (Skip*)malloc(sizeof(Skip));
	newelem->value = addval;
	newelem->point = *pp;
	*pp = newelem;
}

void printSkipList(Skip* head) {
	Skip* p = head;
	while (p) {
		cout << p->value << " ";
		p = p->point;
	}
	cout << endl;
}

void findInSkip(int val, int lvls, Skip **lvlarr) {
	Skip *elem, *prev = NULL;
	int l = lvls, pos = 1;
	elem = lvlarr[l - 1];

	while ((elem) && (elem->value != val)) {
		/*if (elem->value > val) {
			if (!prev) {

			}
		}
		else {
			prev = elem;
			elem = elem->point;
			while (!elem && (l < lvls)) {

			}
		}*/

		if (elem->value > val || !(elem->point)) {
			prev = prev->lowlvl;
			elem = prev->point;
		}
		else {
			prev = elem;
			elem = elem->point;
		}


		//l--;		// (!)
	}
	cout << "found: " << elem->value << endl;
}