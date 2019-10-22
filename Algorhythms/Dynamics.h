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

struct Skip {
	int value;
	Skip* point;
	Skip* lowlvl;
};

void add2List(List** head, int addval);
void printList(List* head);

void fillSkipList(Skip** head, int addval);
void printSkipList(Skip* head);
Skip** createSkipListArr(int lvls, Skip *head, int* checkArrLength);
Skip* findInSkip(int val, int lvls, Skip **lvlarr);

#endif