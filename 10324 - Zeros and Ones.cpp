#include<algorithm>
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	int count = 1;
	while (getline(cin, str) && !str.empty()) {
		cout << "Case " << count++ << ":" << endl;
		int tests, i, j;
		cin >> tests;
		for (int a = 0; a < tests; a++) {
			cin >> i >> j;
			char c = str[min(i, j)];
			bool flag = true;
			for (int b = min(i, j) + 1; b <= max(i, j); b++) {
				if (str[b] != c) {
					flag = false;
					break;
				}
			}
			cout << ((flag) ? "Yes" : "No") << endl;
		}
    
    // Needed to eat the '\n' in the input buffer left by "cin"
		getline(cin, str);
	}
	return 0;
}
