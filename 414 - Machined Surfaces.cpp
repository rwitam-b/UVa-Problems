#include<iostream>
#include<string>

using namespace std;

int main() {
	int N;
	string str;
	cin >> N;
	while (N) {
		getline(cin, str);
		int *spaces = new int[N];
		int min = 26, result = 0;
		for (int a = 0; a < N; a++) {
			getline(cin, str);
			int first = str.find(" ");
			int last = str.find_last_of(" ");
			if ((first == last) && first < 0) {
				spaces[a] = 0;
			}
			else {
				spaces[a] = last - first + 1;
			}
			if (spaces[a] < min) {
				min = spaces[a];
			}
		}
		for (int a = 0; a < N; a++) {
			result += spaces[a] - min;
		}
		cout << result << endl;
		delete spaces;
		cin >> N;
	}
	return 0;
}
