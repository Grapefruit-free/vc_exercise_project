#include<stdio.h>
#include<stdlib.h>

#include"node.h"

/*
typedef struct _node {
	int value;
	struct _node* next;
}Node;

typedef struct _list {
	Node*head;
}List;
*/


int main(void) {
	List list;
	list.head = NULL;
	int number;

	do {
		scanf_s("%d", &number);
		if (number != -1) {
			add(&list, number);
		}
	} while (number != -1);
	delete(&list, 8);
	print(&list);
	return EXIT_SUCCESS;
}
