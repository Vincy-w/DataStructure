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
	int c = 0;
	int a=0, b=0;
	while (a < La.length && b < Lb.length) {
		if (La.data[a] < Lb.data[b]) {
			Lc.data[c++] = La.data[a++];
		}
		else {
			Lc.data[c++] = Lb.data[b++];
		}
	}
	while (a < La.length) {
		Lc.data[c++] = La.data[a++];
	}
	while (b < Lb.length) {
		Lc.data[c++] = Lb.data[b++];
	}
	Lc.length = c;
	return Lc;
}

/**
* p18-2.08 ��֪��һά����A[m+n]�����δ���������Ա�(a1,...,am)��(b1,...,bn)��
* ��дһ��������������������˳����λ�û���������(b1,...,bn)����(a1,...,am)��ǰ�档
*/


/**
* p18-2.09 ���Ա�(a1,...,an)�е�Ԫ�ص��������Ұ�˳��洢�ڼ�����ڡ�
* Ҫ�����һ���㷨�����������ʱ���ڱ��в�����ֵΪx��Ԫ�أ�
* ���ҵ������������Ԫ��λ���ཻ����
* ���Ҳ��������������в�ʹ����Ԫ���Ե�������
*/
void FindX(SqList& L,ElemType x) {
	int low = 0, high = L.length - 1, mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (L.data[mid] == x)break;
		if (L.data[mid] < x)low = mid + 1;
		else high = mid - 1;
	}
	if (L.data[mid] == x && mid != L.length - 1) {
		L.data[mid] = L.data[mid + 1];
		L.data[mid + 1] = x;
	}
	if (low > high) {
		for (int i = ++L.length - 1; i > high+1; i--) {
			L.data[i] = L.data[i - 1];
			L.data[i - 1] = x;
		}
	}
}

/**
* p18-2.10 �轫n(n>1)��������ŵ�һά����R�С�
* ���һ����ʱ��Ϳռ������涼�����ܸ�Ч���㷨��
* ��R�б��������ѭ������p(0<p<n)��λ�ã�
* ����R�е������ɣ�X0,X1,...,Xn-1���任Ϊ��Xp,Xp+1,...,Xn-1,X0,X1,...,Xp-1����
*/
//�㷨˼�룺��X0-Xp-1���浽һ�������У���Xp-Xn-1ǰ�ƣ���X0-Xp-1���Ƶ�ĩβ
void Reverse(SqList& L, int from, int to) {
	int temp;
	for (int i = 0; i < (to - from + 1) / 2; i++) {
		temp = L.data[from + i];
		L.data[from + i] = L.data[to - i];
		L.data[to - i] = temp;
	}
}
void LeftMove(SqList& L, int p) {
	Reverse(L, 0, p - 1);
	Reverse(L, p, L.length - 1);
	Reverse(L, 0, L.length - 1);
}

/**
* **p18-2.11** һ������ΪL(L>=1)����������S�����ڵ�L/2������ȡ������λ�õ�����ΪS����λ����
�磬����S1=��11��13��15��17��19������S1����λ����15��
�������е���λ���Ǻ���������Ԫ�ص��������е���λ�����磬S2=��2��4��6��8��20����
��S1��S2����λ����11.�������ȳ����У�����Ƹ�Ч�㷨���ҳ�������A��B����λ����
*/
int M_Search(SqList& A, SqList& B) {
	int s1 = 0, d1 = A.length-1, m1, s2 = 0, d2 = A.length-1, m2;
	while (s1 != d1 || s2 != d2) {
		m1 = (s1 + d1) / 2;
		m2 = (s2 + d2) / 2;
		if (A.data[m1] == B.data[m2])
			return A.data[m1];
		if (A.data[m1] < B.data[m2]) {
			if ((s1 + d1) % 2 == 0) {
				s1 = m1;
				d2 = m2;
			}
			else {
				s1 = m1 + 1;
				d2 = m2;
			}
		}
		else {
			if ((s2 + d2) % 2 == 0) {
				d1 = m1;
				s2 = m2;
			}
			else {
				d1 = m1;
				s2 = m2 + 1;
			}
		}
	}
	return A.data[s1] < B.data[s2] ? A.data[s1] : B.data[s2];
}

/**
* p18-2.12 ��֪һ��������A=(a0,a1...an-1)������0<=ai<n��
������ap1=ap2=...=apm=x��m>n/2��
���xΪA����Ԫ�أ�����A=��0��5��5��3��5��7��5��5������5Ϊ��Ԫ�أ�
����A=��0��5��5��3��5��1��5��7������A��û����Ԫ�ء�
����A�е�n��Ԫ�ر�����һ��һά�����У������һ��Ч�㷨���ҳ�A����Ԫ�أ��������-1��
*/
int Majority(SqList& A) {
	int c=A.data[0], count = 1;
	for (int i = 1; i < A.length; i++) {
		if (A.data[i] == c)
			count++;
		else if (count > 0)
			count--;
		else {
			c = A.data[i];
			count = 1;
		}
	}
	if (count > 0) {
		for (int i = count = 0; i < A.length; i++) {
			if (A.data[i] == c)
				count++;
		}
	}
	if (count > A.length / 2) return c;
	else return -1;
}

/**
* p19-2.13 ����һ����n(n>=1)�����������飬�����һ����ʱ���Ͼ����ܸ�Ч���㷨��
�ҳ�������δ���ֵ���С��������
�磬����{-5��3��2��3}��δ���ֵ���С��������1��
����{1��2��3}��δ���ֵ���С��������4��
*/
int findPosMin(SqList& A) {
	int *b=new int[A.length];
	for (int i = 0; i < A.length; i++)
		b[i] = 0;
	for (int i = 0; i < A.length; i++) {
		if (A.data[i] > 0 && A.data[i] <= A.length)
			b[A.data[i] - 1]++;
	}
	for (int i = 0; i < A.length; i++) {
		if (b[i] == 0)return i + 1;
	}
	return A.length+1;
}

/**
* p19-2.14 ������Ԫ�飨a,b,c����a,b,c��Ϊ�������ľ���D=|a-b|+|b-c|+|c-a|��
����3���ǿ���������S1��S2��S3��������ֱ�洢��3�������С�
�����һ����Ч�㷨������S1={-1��0��9}��S2={-25��-10��10��11}��
S3={2��9��17��30��41}������С����Ϊ2����Ӧ��Ԫ��Ϊ��9,10,9����
*/
//????????����