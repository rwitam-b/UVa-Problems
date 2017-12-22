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
	cout << "Lumberjacks:" << endl;
	while (T--) {
		getline(cin, str);
		s = stringstream(str);
		int num1, num2, asc = 0, desc = 0;
		s >> num1;
		while (s.good()) {
			s >> num2;
			if (num1 < num2) {
				asc++;
			}
			else if (num1 > num2) {
				desc++;
			}
			num1 = num2;
		}
		cout << ((asc && desc) ? "Unordered" : "Ordered") << endl;
	}
	return 0;
}
