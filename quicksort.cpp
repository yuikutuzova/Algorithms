
#include<cstdlib>
#include<iostream>
#include<vector>
#define ARR_SIZE 500

using namespace std;
int median(int a, int b, int c)
{
	if (a > b) {
		if (c > a)
			return a;
		return (b > c) ? b : c;
	}
	if (c > b)
		return b;
	return (a > c) ? a : c;
}

void insert_sort(vector<int> &arr, int l, int r)
{
	for (int i = l; i <= r; i++) {
		int j = i;
		int temp;
		while (j > 0 && arr[j] < arr[j - 1]) {
			swap(arr[j], arr[j - 1]);
			j--;
		}
	}
}

void quicksort(vector<int> &arr, int left_border, int right_border)
{
	if (left_border - right_border <= 10) {       //use insertion to avoid extra recursion
		insert_sort(arr, left_border, right_border);
		return;
	}
	int pivot = median(arr[rand() % right_border + left_border], arr[rand() % ((left_border + right_border) / 2) + left_border], arr[rand() % right_border + left_border]);
	int i = left_border;
	int j = right_border;
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++; j--;
		}
	}
	if (i < right_border) quicksort(arr, i, right_border);
	if (left_border < j) quicksort(arr, left_border, j);
}


int main()
{
	vector<int> arr(ARR_SIZE);
	for (int i = 0; i < ARR_SIZE; i++) {
		arr[i] = rand();
	}
	quicksort(arr, 0, ARR_SIZE - 1);
	for (int i = 0; i < ARR_SIZE; i++)
	{
		cout << arr[i] << " ";
	}

}