#include"node.h"
#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>
void add(List* plist, int number);//链表增加函数
void print(List* plist);//输出链表数据
void find(List* plist, int number);//查找链表某个数据,并且输出他的地址
void delete(List* plist, int number);//删除输入数据所指向的链表
void deleteAll(List* plist);//删除所有的链表


void add(List* plist, int number) {
	Node* p = malloc(sizeof(Node));
	p->value = number;
	p->next = NULL;
	Node* last = plist->head;
	if (last) {
		while (last->next) {
			last = last->next;
		}
		last->next = p;
	}
	else {
		plist->head = p;
	}
}
void print(List* plist) {
	Node* p;
	for (p = plist->head; p; p = p->next) {
		printf("%d\n", p->value);
	}
}
void find(List* plist, int number) {
	Node* p;
	int isFind = 0;
	for (p = plist->head; p; p = p->next) {
		if (p->value == number) {
			isFind = 1;
			printf("找到了,他的地址是%p", p);
			break;
		}
	}
	if (!isFind) {
		printf("没找到");
	}
}
void delete(List* plist, int number) {
	Node* p, * q;
	for (q = NULL, p = plist->head; p; q = p, p = p->next) {
		if (p->value == number) {
			if (q) {
				q->next = p->next;
			}
			else {
				plist->head = p->next;
			}
			free(p);
			break;
		}
	}
}
void deleteAll(List* plist) {
	Node* p, * q;
	for (p = plist->head; p; p = q) {
		q = p->next;
		free(p);
	}
}