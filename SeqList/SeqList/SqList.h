#pragma once
#define ElemType int
#define MaxSize 50

struct SqList {
	ElemType data[MaxSize];
	int length = 0;
};

bool CreatList(SqList& L, int* a, int alen);//�������鴴������
void PrintList(SqList& L);//��ӡ

int DelMin(SqList& L);//p18-2.01��˳�����ɾ��������Сֵ
void ReverseList(SqList& L);//2.02Ԫ������
void DelX(SqList& L,ElemType x);//2.03ɾ�����Ա�������ֵΪx������Ԫ��
void DelSToT(SqList& L, ElemType s, ElemType t);//������˳�����ɾ����ֵ�ڸ���ֵs��t֮�䣨Ҫ��s<t��������Ԫ��
void DelSAndT(SqList& L, int s, int t);//ɾ����ֵ�ڸ���ֵs��t֮�䣨����st,Ҫ��s<t��������Ԫ��
void DelRepeat(SqList& L);//ɾ��������ֵ�ظ���Ԫ��
SqList MergeList(SqList La, SqList Lb);//����������˳���ϲ�
void FindX(SqList& L, ElemType x);//������ֵΪx��Ԫ��
void LeftMove(SqList& L, int p);//��R�б��������ѭ������p(0<p<n)��λ��