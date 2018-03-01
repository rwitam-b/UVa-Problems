#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main() {
	int M;
	string str;
	cin >> M;
	getline(cin, str);
	getline(cin, str);
	while (M--) {		
		int N, K;
		cin >> N >> K;
		getline(cin, str);
		bool *coin = new bool[N];
		fill(coin, coin + N, false);
		while (K--) {
			string numbers, operation;
			getline(cin, numbers);
			getline(cin, operation);
			if (!operation.compare("=")) {
				stringstream ss(numbers);
				int each;
				ss >> each;
				for (int a = 0; a < (2 * each); a++) {
					int temp;
					ss >> temp;
					coin[temp - 1] = true;
				}
			}
		}
		int falseCount = 0, falsePos;
		for (int a = 0; a < N; a++) {
			if (!coin[a]) {
				falseCount++;
				falsePos = a;
			}
		}		
		if (falseCount > 1) {
			cout << 0 << endl;
		}
		else {
			cout << falsePos + 1 << endl;
		}
		delete coin;
		getline(cin, str);
		if (M != 0) {
			cout << endl;
		}
	}
	return 0;
}
