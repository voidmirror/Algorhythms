#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "Dynamics.h"

using namespace std;

int main() {
	/*
	List *head = 0;
	srand(time(0));
	for (int i = 0; i < 100; ++i)
		add2List(&head, rand() % 10 + 48);
	printf("Elements of the list:\n");
	printList(head);

	doubleList *dhead = 0;
	*/

	int checkArrLength = 0;
	int *checkArrLengthP = &checkArrLength;

	Skip* skip = NULL;
	for (int i = 0; i < 10; i++) {
		fillSkipList(&skip, (rand() % 10));
	}
	printSkipList(skip);
	
	Skip** arr = createSkipListArr(3, skip, checkArrLengthP);

	printSkipList(arr[2]);
	cout << checkArrLength;
}