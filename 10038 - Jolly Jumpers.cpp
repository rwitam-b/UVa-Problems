#include<iostream>
#include<string>
#include<sstream>

using namespace std;

bool checkAllSet(bool *arr, int size) {
	for (int a = 1; a < size; a++) {
		if (!arr[a]) {
			return false;
		}
	}
	return true;
}

int main() {
	string str;
	while (getline(cin, str) && !str.empty()) {
		stringstream ss(str);
		int N, temp, last;
		ss >> N;
		bool *flags = new bool[N];
		fill(flags, flags + N, false);
		ss >> last;
		while (ss.good()) {
			ss >> temp;
			int pos = abs(last - temp);
			if (pos < N)
				flags[pos] = true;
			last = temp;
		}
		cout << (checkAllSet(flags, N) ? "Jolly" : "Not jolly") << endl;
		delete[]flags;
	}
	return 0;
}
