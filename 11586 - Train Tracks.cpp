#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	int T;
	string str;
	stringstream s;
	cin >> T;
	getline(cin, str);
	while (T--) {
		getline(cin, str);
		s = stringstream(str);
		int m = 0, f = 0, mf = 0, pieces = 0;
		bool loop = false;
		while (s.good()) {
			pieces++;
			s >> str;
			if (!str.compare("MM")) {
				m += 2;
			}
			else if (!str.compare("FF")) {
				f += 2;
			}
			else {
				mf++;
			}
		}if (pieces > 1) {
			if (mf > 1) {
				m++;
				f++;
			}
			if (m == f) {
				loop = true;
			}
		}
		cout << (loop ? "LOOP" : "NO LOOP") << endl;
	}
	return 0;
}
