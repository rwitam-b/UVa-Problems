#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	int T, count = 1;
	string str;
	stringstream ss;
	cin >> T;
	getline(cin, str);
	while (T--) {
		cout << "Case #" << count++ <<":"<< endl;
		string arr[10];
		int max = -1, temp;
    
    // Find max relevance here
		for (int a = 0; a < 10; a++) {
			getline(cin, arr[a]);
			ss = stringstream(arr[a]);
			ss >> str;
			ss >> temp;
			if (temp > max) {
				max = temp;
			}
		}
    
    // Print websites with the obtained max relevance
		for (int a = 0; a < 10; a++) {
			ss = stringstream(arr[a]);
			ss >> str;
			ss >> temp;
			if (temp == max) {
				cout << str << endl;
			}
		}
	}
	return 0;
}
