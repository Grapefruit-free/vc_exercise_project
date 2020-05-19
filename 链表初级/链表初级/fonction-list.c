#include"node.h"
#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>
void add(List* plist, int number);//�������Ӻ���
void print(List* plist);//�����������
void find(List* plist, int number);//��������ĳ������,����������ĵ�ַ
void delete(List* plist, int number);//ɾ������������ָ�������
void deleteAll(List* plist);//ɾ�����е�����


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
			printf("�ҵ���,���ĵ�ַ��%p", p);
			break;
		}
	}
	if (!isFind) {
		printf("û�ҵ�");
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