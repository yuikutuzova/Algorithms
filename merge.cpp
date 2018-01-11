#include "stdafx.h"
#include <iostream>
#include "stdio.h"
#include "stdlib.h"

using namespace std;
int begin, end;

void Merge(int *A, int begin, int mid, int end);

void  MergeSort(int *A, int begin, int end)
{
	if (begin < end)
	{
		int mid = ((end + begin) / 2);

		MergeSort(A, begin, mid);
		MergeSort(A, mid + 1, end);

		Merge(A, begin, mid, end);
	}
}

void Merge(int *A, int begin, int mid, int end)
{
	int *Arr = (int*)malloc((end - begin + 1) * sizeof(int));
	int lArr = 0;
	int l = begin, p = mid + 1;

	for (int i = begin; i <= end; i++) {
		if (l > mid)      //левая часть дошла ли до конца
		{
			Arr[lArr++] = A[p++];
		}
		else if (p > end)   //правая часть дошла ли до конца
		{
			Arr[lArr++] = A[l++];
		}
		else if (A[l] < A[p])     //сравниваем элементы правой и левой части
		{
			Arr[lArr++] = A[l++];
		}
		else
		{
			Arr[lArr++] = A[p++];
		}
	}
	for (int i = 0; i< lArr; i++) //формируем отсортированный массив
		A[begin++] = Arr[i];
	free(Arr);
}


int main()
{
	int n;
	cin >> n;
	int arr[100];
	for (int i = 1; i <= n; i++) {
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	}
	cout << endl;
	MergeSort(arr, 1, n);
	for (int i = 1; i <= n; i++)
		cout << arr[i] << " ";
	return 0;
}
