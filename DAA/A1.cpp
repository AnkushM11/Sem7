#include <bits/stdc++.h>
using namespace std;

int dp[20005];

int ifib(int n) {
	int prev = 0, current = 1;
	for (int i = 2; i <= n; i++) {
		int next = prev + current;
		prev = current;
		current = next;
	}
	return current;
}

int rsteps = 0;
int rfib(int n) {
	rsteps++;
	if (n == 1 || n == 0) {
		return n;
	} else {
		return (rfib(n - 1) + rfib(n - 2));
	}
}

int rosteps = 0;
int rofib(int n) {
	if (n == 1 || n == 0) {
		return n;
	}
	int& ans = dp[n];
	if (ans != -1) {
		return ans;
	}
	rosteps++;
	return ans = (rofib(n - 1) + rofib(n - 2));
}

int main() {
	cout << " Enter the number : ";
	int n;
	cin >> n;

	memset(dp, -1, sizeof(dp));

	cout << " Fibonnaci of a number using iteration is : " << ifib(n) << endl;
	cout << " Number of Steps required using iteration : " << n << endl;
	cout << " Fibonnaci of a number using Recursion is : " << rfib(n) << endl;
	cout << " Number of Steps required using Recursion : " << rsteps << endl;

	cout << " Fibonnaci of a number using (Optimised) Recursion is : " << rofib(n) << endl;
	cout << " Number of Steps required using Recursion : " << rosteps << endl;

	return 0;
}