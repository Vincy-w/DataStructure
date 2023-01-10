#pragma once

struct Lnode {
	int data;
	Lnode* next;
};

using LinkList = Lnode*;

void InitList(LinkList& L);//初始化
void CreatList(LinkList& L, int* a, int n);//由数组创建链表 
void PrintList(LinkList& L);//打印