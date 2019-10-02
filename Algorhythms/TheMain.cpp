#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "Dynamics.h"

int main() {
	List *head = 0;
	srand(time(0));
	for (int i = 0; i < 100; ++i)
		add2List(&head, rand() % 10 + 48);
	printf("Elements of the list:\n");
	printList(head);

	doubleList *dhead = 0;
}