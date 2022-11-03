#pragma once
#define ElemType int
#define MaxSize 50

struct SqList {
	ElemType data[MaxSize];
	int length = 0;
};

bool CreatList(SqList& L, int* a, int alen);//根据数组创建链表
void PrintList(SqList& L);//打印

int DelMin(SqList& L);//p18-2.01从顺序表中删除具有最小值
void ReverseList(SqList& L);//2.02元素逆置
void DelX(SqList& L,ElemType x);//2.03删除线性表中所有值为x的数据元素
void DelSToT(SqList& L, ElemType s, ElemType t);//从有序顺序表中删除其值在给定值s与t之间（要求s<t）的所有元素
void DelSAndT(SqList& L, int s, int t);//删除其值在给定值s与t之间（包含st,要求s<t）的所有元素
void DelRepeat(SqList& L);//删除所有其值重复的元素
SqList MergeList(SqList La, SqList Lb);//将两个有序顺序表合并
void FindX(SqList& L, ElemType x);//查找数值为x的元素
void LeftMove(SqList& L, int p);//将R中保存的序列循环左移p(0<p<n)个位置