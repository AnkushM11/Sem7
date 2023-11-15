#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ans;

void n_queen(int col,
vector<string>& board,
vector<bool>& leftrow,
vector<bool>& upperdiagonal,
vector<bool>& lowerdiagonal,
int n) {
	if (n == col) {
		ans.push_back(board);
		return;
	}
	for (int row = 0; row < n; row++) {
		if (leftrow[row] == 0 && upperdiagonal[n - 1 - row + col] == 0 &&
		lowerdiagonal[row + col] == 0) {
			leftrow[row] = 1;
			upperdiagonal[n - 1 - row + col] = 1;
			lowerdiagonal[row + col] = 1;

			board[row][col] = 'Q';
			n_queen(col + 1, board, leftrow, upperdiagonal, lowerdiagonal, n);
			board[row][col] = '.';

			leftrow[row] = 0;
			upperdiagonal[n - 1 - row + col] = 0;
			lowerdiagonal[row + col] = 0;
		}
	}
}

int main() {
	int n;
	cout << "Enter the size of Chess board : ";
	cin >> n;

	string s(n, '.');
	vector<string> board(n);
	for (int i = 0; i < n; i++) {
		board[i] = s;
	}

	vector<bool> leftrow(n, 0), upperdiagonal(2 * n - 1, 0), lowerdiagonal(2 * n - 1, 0);
	n_queen(0, board, leftrow, upperdiagonal, lowerdiagonal, n);

	cout << "Total Solutions are  " << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << endl;
		}
		cout << endl;
	}
	return 0;
}

/*
	Time Complexity: O(N!)
	Auxiliary Space: O(N^2)
*/

// #include <bits/stdc++.h>
// using namespace std;

// int n;

// void printSolution(vector<vector<int>>& board) {
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			cout << board[i][j] << " ";
// 		}
// 		cout << endl;
// 	}
// }

// bool isSafe(int row, int col, vector<vector<int>>& board) {
// 	int duprow = row;
// 	int dupcol = col;
// 	while (row >= 0 && col >= 0) {
// 		if (board[row][col]) {
// 			return false;
// 		}
// 		row--;
// 		col--;
// 	}
// 	row = duprow;
// 	col = dupcol;
// 	while (col >= 0) {
// 		if (board[row][col]) {
// 			return false;
// 		}
// 		col--;
// 	}
// 	row = duprow;
// 	col = dupcol;
// 	while (row < n && col >= 0) {
// 		if (board[row][col]) {
// 			return false;
// 		}
// 		row++;
// 		col--;
// 	}
// 	return true;
// }

// bool solution(int col, vector<vector<int>>& board) {
// 	if (col >= n) {
// 		return true;
// 	}
// 	for (int row = 0; row < n; row++) {
// 		if (isSafe(row, col, board)) {
// 			board[row][col] = 1;
// 			if (solution(col + 1, board)) {
// 				return true;
// 			}
// 			board[row][col] = 0;
// 		}
// 	}
// 	return false;
// }

// int main() {
// 	cout << "Enter the dimension of the chess board : ";
// 	cin >> n;
// 	vector<vector<int>> board(n + 1, vector<int>(n + 1, 0));
// 	if (!solution(0, board)) {
// 		cout << "Solution doesn't Exist !!" << endl;
// 	} else {
// 		printSolution(board);
// 	}
// 	return 0;
// }
