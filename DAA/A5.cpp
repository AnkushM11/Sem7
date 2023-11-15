#include <bits/stdc++.h>
using namespace std;

int partition(int low, int high, vector<int>& arr) {
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j < high; j++) { // mistake
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return i + 1; //
}

void deterministicQuickSort(vector<int>& arr, int low, int high) {
	if (low < high) {
		int pivot = partition(low, high, arr);
		deterministicQuickSort(arr, low, pivot - 1);
		deterministicQuickSort(arr, pivot + 1, high);
	}
}

int randomPartition(vector<int>& arr, int low, int high) {
	int pivot = low + rand() % (high - low + 1);
	swap(arr[pivot], arr[high]);
	return partition(low, high, arr);
}

void randomizedQuickSort(vector<int>& arr, int low, int high) {
	if (low < high) {
		int pivot = randomPartition(arr, low, high);

		randomizedQuickSort(arr, low, pivot - 1);
		randomizedQuickSort(arr, pivot + 1, high);
	}
}

int main() {
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;

	vector<int> arr(n);
	srand(time(0));
	cout << "Enter " << n << " integers:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> deterministicArr = arr;
	vector<int> randomizedArr = arr;

	deterministicQuickSort(deterministicArr, 0, n - 1);
	randomizedQuickSort(randomizedArr, 0, n - 1);

	cout << "Deterministic Sorted Array: ";
	for (int i = 0; i < n; i++) {
		cout << deterministicArr[i] << " ";
	}
	cout << endl;

	cout << "Randomized Sorted Array: ";
	for (int i = 0; i < n; i++) {
		cout << randomizedArr[i] << " ";
	}
	cout << endl;
	return 0;
}