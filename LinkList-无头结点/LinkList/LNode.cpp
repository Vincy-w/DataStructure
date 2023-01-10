#include "LNode.h"
#include <iostream>
using namespace std;

//��ʼ��
void InitList(LinkList& L) {
	L = NULL;
}

//�������鴴������,β�巨
void CreatList(LinkList& L, int* a, int n) {
	L = new Lnode;
	Lnode* r = L;
	r->data = a[0];
	r->next = nullptr;
	for (int i = 1; i < n; i++) {
		Lnode* p = new Lnode;
		p->data = a[i];
		p->next = NULL;
		r->next = p;
		r = r->next;
	}
}

//��ӡ����
void PrintList(LinkList& L) {
	Lnode* p = L;
	while (p)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}