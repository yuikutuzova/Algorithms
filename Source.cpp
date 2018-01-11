#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
int median(int a, int b, int c)
{ if (a > b) {
	if (c > a) return a;
	return (b > c) ? b : c; 
}
if (c > b) return b; 
return (a > c) ? a : c;
} 
void insert_sort(vector<int> &arr, int l, int r) {
	for (int i = l; i <= r; i++) {
		int j = i; int temp;
		while (j > 0 && arr[j] < arr[j - 1]) {
			swap(arr[j], arr[j - 1]); j--; 
		}
	} 
} 
void quicksort(vector<int> &arr, int l, int r) {
	if (l - r <= 10) { 
		insert_sort(arr, l, r);
		return; 
	} 
	int piv = median(arr[rand() % r + l], arr[rand() % ((l + r) / 2) + l], arr[rand() % r + l]);
	int i = l;
	int j = r;
	while (i <= j) {
		while (arr[i] < piv) i++;
		while (arr[j] > piv) j--; if (i <= j) {
			swap(arr[i],arr[j]); i++; j--; 
		} 
	} 
	if (i < r) quicksort(arr, i, r);
	if (l < j) quicksort(arr, l, j);
} 

void test1() {
		const int size = 10;
		vector<int> arr(size);
		for (int i = 0; i < size; i++) {
			arr[i] = rand() % 100;
		}
		quicksort(arr, 0, size - 1);
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
	}

void test2()
 {
		vector<int> A = { -13,-34, 542, 10011, 122, 999, 190, 1, 6, 9999 };
	 	cout << endl;
		cout << "expected result:\n" << -34 << " " << -13 << " " << 1 << " " << 6 << " " << 122 << " " << 190 << " " << 542 << " " << 999 << " " << 9999 << " " << 10011 << " " << endl;
		quicksort(A, 0, 9);
		for (int i = 0; i <= 9; i++)
			cout << A[i] << " ";
}

int main() 
{ 
	test1();
	test2();
} 