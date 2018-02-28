#include<iostream>
#include<string>
#include<sstream>
#include<map>


using namespace std;

int main() {
	int temp, N;
	string str1, str2;
	stringstream ss1, ss2;
	cin >> N;
	getline(cin, str1);
	getline(cin, str1);
	for (int a = 0; a < N; a++) {
		map<int, string> lookup;
		getline(cin, str1);
		getline(cin, str2);
		ss1 = stringstream(str1);
		ss2 = stringstream(str2);
		while (ss1.good() && ss2.good()) {
			ss1 >> temp;
			ss2 >> str1;
			lookup[temp] = str1;
		}
		if (a != 0) {
			cout << endl;
		}
		for (auto iterator : lookup) {
			cout << iterator.second << endl;
		}
		lookup.clear();
		getline(cin, str1);
	}
	return 0;
}
