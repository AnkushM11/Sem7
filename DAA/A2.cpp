#include <bits/stdc++.h>
using namespace std;

struct MinHeapCode {
	char data;
	int freq;
	MinHeapCode *left, *right; // pointers
	MinHeapCode(char data, int freq) {
		this->data = data;
		this->freq = freq;
		left = right = NULL;
	}
};

void printCodes(struct MinHeapCode* root, string str) {
	if (root == NULL) {
		return;
	}
	if (root->data != '$') {
		cout << root->data << " --> " << str << endl;
	}
	printCodes(root->left, str + '0');
	printCodes(root->right, str + '1');
}

struct Compare {
	bool operator()(struct MinHeapCode* a, struct MinHeapCode* b) {
		return a->freq > b->freq;
	}
};

void HuffmanCode(char alphabets[], int frequency[], int n) {
	priority_queue<MinHeapCode*, vector<MinHeapCode*>, Compare> minHeap; // syntax
	for (int i = 0; i < n; i++) {
		minHeap.push(new MinHeapCode(alphabets[i], frequency[i]));
	}
	MinHeapCode *left, *right, *temp;
	while (minHeap.size() != 1) {
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		temp = new MinHeapCode('$', left->freq + right->freq);
		temp->left = left;
		temp->right = right;
		minHeap.push(temp);
	}
	printCodes(minHeap.top(), " ");
}

int main() {
	int n;
	cout << "Enter the number of characters : ";
	cin >> n;
	char alphabets[n];
	cout << "Enter the " << n << " characters (space Separated):";
	for (int i = 0; i < n; i++) {
		cin >> alphabets[i];
	}
	int frequency[n];
	cout << "Enter the frequency of each character : " << endl;
	for (int i = 0; i < n; i++) {
		cout << alphabets[i] << "-->";
		cin >> frequency[i];
	}
	HuffmanCode(alphabets, frequency, n);
	return 0;
}