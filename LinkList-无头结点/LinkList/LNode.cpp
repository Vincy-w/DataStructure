#include "LNode.h"
#include <iostream>
using namespace std;

//初始化
void InitList(LinkList& L) {
	L = NULL;
}

//根据数组创建链表,尾插法
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

//打印链表
void PrintList(LinkList& L) {
	Lnode* p = L;
	while (p)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}