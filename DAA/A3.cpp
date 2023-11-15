#include <bits/stdc++.h>
using namespace std;

int solve(int n, int w, vector<int>& wt, vector<int>& val) {
	vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) {
			if (wt[i - 1] > j) {
				dp[i][j] = dp[i - 1][j];
			} else {
				dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
			}
		}
	}
	return dp[n][w];
}

int main() {
	cout << "--------------Knapsack Problem ---------------------" << endl;
	cout << "Enter the number of Items : ";
	int n;
	cin >> n;
	cout << "Enter maximum allowed weight: ";
	int W;
	cin >> W;

	vector<int> profit;
	vector<int> weight;

	for (int i = 0; i < n; i++) {
		int a, b;
		cout << "Enter weight of item " << i + 1 << " : ";
		cin >> a;
		cout << "Enter value of item " << i + 1 << " : ";
		cin >> b;
		weight.push_back(a);
		profit.push_back(b);
	}
	int maxProfit = solve(n, W, weight, profit);
	cout << "Maximum profit is: " << maxProfit << endl;

	return 0;
}