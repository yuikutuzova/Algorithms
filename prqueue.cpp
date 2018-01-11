#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>

using namespace std;


class Queue
{
	vector<int> arr;
	int parent(int i)
	{
		return (i - 1) / 2;
	}

	void heapify(int index)//Значение элемента меньше, чем у хотя бы одного из его потомков, => элемент должен занять место ниже
	{
		int maxI;
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		if (left < arr.size() && arr[left] > arr[index])
			maxI = left;
		else
			maxI = index;
		if (right < arr.size() && arr[right] > arr[maxI])
			maxI = right;
		if (index != maxI)
		{
			swap(arr[index], arr[maxI]);
			heapify(maxI);
		}
	}
	void up(int index, int el)//Значение элемента больше, чем у его родителя, и поэтому элемент должен занять место выше, чем имеет сейчас
	{
		arr[index] = el;
		while (index > 0 && arr[parent(index)] < arr[index])
		{
			swap(arr[index], arr[parent(index)]);
			index = parent(index);
		}
	}
public:

	int top()//получение значения элемента с максимальным приоритетом
	{
		return arr.front();
	}

	int pop()//удаление элемента с максимальным приоритетом
	{
		int max = arr[0];
		arr[0] = arr[arr.size() - 1];
		arr.resize(arr.size() -1);
		heapify(0);
		return max;
	}

	void print_heap()
	{
		for (int i = 0; i < arr.size(); i++)
			cout << arr[i] << " ";
		cout << endl;
	}



	void push(int el)//добавление элемента в очередь
	{
		arr.resize(arr.size()+1);
		up(arr.size() - 1, el);
	}

	bool isEmpty()
	{
		return arr.size() == 0 ? true : false;
	}

	int size()//кол-во элементов
	{
		return arr.size();
	}

};

void test1()
{
	Queue pq;
	cout << pq.isEmpty() << endl;
	pq.push(1);
	pq.push(3);
	pq.push(2);
	int max = pq.pop();
	pq.print_heap();
	
}
int main()
{
	test1();
}