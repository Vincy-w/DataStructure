#pragma once

struct Lnode {
	int data;
	Lnode* next;
};

using LinkList = Lnode*;

void InitList(LinkList& L);//��ʼ��
void CreatList(LinkList& L, int* a, int n);//�����鴴������ 
void PrintList(LinkList& L);//��ӡ