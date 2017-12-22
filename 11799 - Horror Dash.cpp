#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	int count = 1, T;
	string str;
	stringstream s;
	cin >> T;
	getline(cin, str);
	while (T--) {
		int max = -1;
		getline(cin, str);
		s = stringstream(str);
		while (s.good()) {
			int temp;
			s >> temp;
			if (temp >= max) {
				max = temp;
			}
		}
		cout << "Case " << count++ << ": " << max << endl;
	}
	return 0;
}
