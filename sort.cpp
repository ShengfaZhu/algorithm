#include <iostream>
#include <cstdlib>//rand()
#include "time.h"//time()
#include <algorithm> sort

using namespace std;

void merge(double *_Array, int p, int q, int r)//p:第0个，r:第n-1个，q:第(r+p)/2个
{
	int len1 = q - p + 1;
	int len2 = r - q;
	double *L = new double[len1 + 1];
	double *R = new double[len2 + 1];
	for (int i = 0; i < len1; i++)//Array数组左边放入L数组中
	{
		L[i] = _Array[p + i];
	}
	for (int i = 0; i < len2; i++)//Array数值右边放入R数值中
	{
		R[i] = _Array[q + 1 + i];
	}
	L[len1] = INT_MAX;
	R[len2] = INT_MAX;//无穷大
	int i = 0;
	int j = 0;
	for (int k = p; k <= r; k++)//将小的数值放入_Array数组中
	{
		if (L[i] < R[j])
		{
			_Array[k] = L[i];
			i++;
		}
		else
		{
			_Array[k] = R[j];
			j++;
		}
	}
}

void mergeSort(double _Array[], int p, int r)
{
	if (p < r)
	{
		int q;
		q= (p + r) / 2;
		mergeSort(_Array, p, q);
		mergeSort(_Array, q + 1, r);
		merge(_Array, p, q, r);
	}
}


int main()
{
	int n = 100;
	double *Array = new double[n];
	srand((unsigned)time(0));
	for (int i = 0; i < n; i++)
	{
		Array[i] = rand() % 101;//生成0-100之间的随机整数
		cout << Array[i] << "\t";
	}
	//mergeSort(Array, 0, n-1);
	sort(Array, Array + n);
	cout << "\n" << "After sort : " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << Array[i] << "\t";
	}
	return 0;
}

