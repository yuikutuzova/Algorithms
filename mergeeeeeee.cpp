#include "stdafx.h"
#include <iostream>
#include "stdio.h"
#include "stdlib.h"

using namespace std;


void Merge(int *A, int left, int mid, int right);

void  MergeSort(int *A, int left, int right)
{
	if (left < right)
	{
		int mid = ((right + left) / 2);

		MergeSort(A, left, mid);
		MergeSort(A, mid + 1, right);

		Merge(A, left, mid, right);
	}
}

void Merge(int *A, int left, int mid, int right)
{
	int *Arr = (int*)malloc((right - left + 1) * sizeof(int));
	int lArr = 0;
	int l = left, p = mid + 1;

	for (int i = left; i <= right; i++) {
		if (l > mid)      //левая часть дошла ли до конца
		{
			Arr[lArr++] = A[p++];
		}
		else if (p > right)   //правая часть дошла ли до конца
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
		A[left++] = Arr[i];
	free(Arr);
}


void test1()
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
}
void test2()
{
	int A[10] = { -1,-3, 122, 111, 122, 9999, 100, 1, 3, 9999 };
	cout << endl;
	cout << "expected result:" << -3 << " "<< -1 << " " << 1 << " " << 3 << " " << 100 << " " << 111 << " " << 122 << " " << 122 << " " << 9999 << " " << 9999 << " " << endl;
	MergeSort(A, 0, 9);
	for (int i = 0; i <= 9; i++)
		cout << A[i] << " ";
	
}
void test3()
{
	cout << endl;
	cout<<"Size 0: expected result - nothing"<<endl;
	int n = 0;
	int *A = (int*)malloc(n * sizeof(int));
	MergeSort(A, 0, n - 1);
	for (int i = 0; i <= n-1; i++)
		cout << A[i] << " ";
	cout << endl;
}

int main()
{
	test1();
	test2();
	test3();
}