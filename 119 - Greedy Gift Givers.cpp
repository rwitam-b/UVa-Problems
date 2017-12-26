#include<string>
#include<iostream>
#include<sstream>
#include<unordered_map>

using namespace std;

int main()
{
	string str, pString;
	stringstream ss;
	int people;
	getline(cin, str);
	while (!str.empty()) {
		ss = stringstream(str);
		ss >> people;
		getline(cin, str);
		pString = str;
		ss = stringstream(str);
		unordered_map<string, int> person;
		for (int a = 0; a < people; a++) {
			string temp;
			ss >> temp;
			person[temp] = 0;
		}
		for (int a = 0; a < people; a++) {
			string from, to;
			int totalMoney, count;
			getline(cin, str);
			ss = stringstream(str);
			ss >> from >> totalMoney >> count;			
			for (int b = 0; b < count; b++) {
				ss >> to;
				person[to] += totalMoney / count;
				person[from] -= totalMoney / count;
			}
		}
		ss = stringstream(pString);
		while (ss.good()) {
			string temp;
			ss >> temp;
			cout << temp << " " << person[temp]<<endl;
		}
		getline(cin, str);
		if (!str.empty()) {
			cout << endl;
		}
	}
	return 0;
}
