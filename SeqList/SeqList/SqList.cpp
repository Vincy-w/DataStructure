#include <iostream>
#include "SqList.h"
using namespace std;

//��������
bool CreatList(SqList& L, int* a, int alen) {
	//�ж�����a�����Ƿ�Ϸ�
	if (alen > MaxSize) {
		cerr << "can not creat!" << endl;
		return false;
	}
	L.length = alen;
	for (int i = 0; i < L.length; i++) {
		L.data[i] = a[i];
	}
	return true;
}

//��ӡ
void PrintList(SqList& L) {
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << ' ';
	}
	cout << endl;
}

/**
* p18-2.01��˳�����ɾ��������Сֵ��Ԫ�أ�����Ψһ�����ɺ������ر�ɾ��Ԫ�ص�ֵ��
* �ճ���λ�������һ��Ԫ�������˳���Ϊ�գ�����ʾ������Ϣ���˳�����
*/
int DelMin(SqList& L) {
	if (L.length == 0) {
		cerr << "List is empty!" << endl;
		return -1;
	}
	int min = L.data[0];
	int count = 0;
	for (int i = 1; i < L.length; i++) {
		if (L.data[i] < min) {
			min = L.data[i];
			count = i;
		}
	}
	L.data[count] = L.data[--L.length];
	return min;
}

/**
* p18-2.02 ���һ����Ч�㷨����˳���L������Ԫ�����ã�Ҫ���㷨�ռ临�Ӷ�ΪO(1)��
*/
void ReverseList(SqList& L) {
	for (int i = 0; i < L.length / 2; i++) {
		int temp = L.data[i];
		L.data[i] = L.data[L.length - i - 1];
		L.data[L.length - i - 1] = temp;
	}
}

/**
* p18-2.03 �Գ���Ϊn��˳���L����дһ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)���㷨��
* ���㷨ɾ�����Ա�������ֵΪx������Ԫ��
*/
void DelX(SqList& L,ElemType x) {
	//for (int i = 0; i < L.length; i++) {
	//	if (L.data[i] == x) {
	//		for (int j = i; j < L.length; j++) {
	//			L.data[j] = L.data[j + 1];
	//		}
	//		--L.length;
	//	}
	//}��������ʱ�临�ӶȲ���Ҫ�󣬳����۴�
	int k = 0;
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] != x) {
			L.data[k++] = L.data[i];
		}
	}
	L.length = k;
}

/**
* p18-2.04 ������˳�����ɾ����ֵ�ڸ���ֵs��t֮�䣨Ҫ��s<t��������Ԫ�أ�
* ��s��t�������˳���Ϊ�գ�����ʾ������Ϣ���˳�����
*/
void DelSToT(SqList& L, ElemType s, ElemType t) {
	if (s >= t||L.length==0||s>L.data[L.length-1]||t<L.data[0]) {
		cerr << "Error range" << endl;
		return;
	}
	int start = 0, end = L.length-1;
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] <= s) {
			start = i+1;
		}
		if (L.data[i] >= t) {
			end = i; break;
		}
	}
	if (start == end) return;
	int differ = end - start;
	for (int i = start; (i+differ) < L.length; i++) {
		L.data[i] = L.data[i + differ];
	}
	L.length -= differ;
}

/**
* p18-2.05 p18-2.04 ������˳�����ɾ����ֵ�ڸ���ֵs��t֮��
*������s��t��Ҫ��s<t��������Ԫ�أ�
* ��s��t�������˳���Ϊ�գ�����ʾ������Ϣ���˳�����
*/
void DelSAndT(SqList& L, int s, int t) {
	if (s >= t || L.length == 0 || s > L.data[L.length - 1] || t < L.data[0]) {
		cerr << "Error range" << endl;
		return;
	}
	int start = 0, end = L.length - 1;
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] >= s) {
			start = i; break;
		}
	}
	for (int j = start; j < L.length; j++) {
		if (L.data[j] > t) {
			end = j; break;
		}
	}
	if (start == end) return;
	int differ = end - start;
	for (int i = start; (i + differ) < L.length; i++) {
		L.data[i] = L.data[i + differ];
	}
	L.length -= differ;
}

/**
* p18-2.06 ������˳�����ɾ��������ֵ�ظ���Ԫ�أ�ʹ��������Ԫ�ص�ֵ����ͬ
*/
void DelRepeat(SqList& L) {
	int now = 0;
	for (int i = 1; i < L.length; i++) {
		if (L.data[i] != L.data[now]) {
			L.data[++now] = L.data[i];
		}
	}
	L.length = now + 1;
}

/**
* p18-2.07 ����������˳���ϲ�Ϊһ���µ�����˳������ɺ������ؽ��˳���
*/
SqList MergeList(SqList La, SqList Lb) {
	SqList Lc;
	int a=0, b=0;
	while (a < La.length && b < Lb.length) {
		
	}
}