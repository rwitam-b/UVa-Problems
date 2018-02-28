#include<iostream>

using namespace std;

int main() {
	int N = 0, count = 1;
	while (cin >> N && N) {
		int *arr = new int[N];
		for (int a = 0; a < N; a++) {
			cin >> arr[a];
		}

		// Calculate mean block height
		int height = 0;
		for (int a = 0; a < N; a++) {
			height += arr[a];
		}
		height /= N;

		// Calculating moves required
		int moves = 0;
		for (int a = 0; a < N; a++) {
			if (arr[a] < height) {
				moves += height - arr[a];
			}
		}
		cout << "Set #" << count++ << endl;
		cout << "The minimum number of moves is " << moves << "." << endl << endl;
	}
	return 0;
}
