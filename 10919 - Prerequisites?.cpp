#include<sstream>
#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

int main()
{
	string str;
	stringstream s;
	while (getline(cin, str) && str[0] != '0') {
		int optedCourses, totalCategories;
		unordered_set<string> takenCourses;
		s = stringstream(str);
		s >> optedCourses >> totalCategories;
		for (int a = 0; a < optedCourses; a++) {
			cin >> str;
			takenCourses.insert(str);
		}
		bool pass = true;
		for (int a = 0; a < totalCategories; a++) {
			int subjects, minToBeTaken, actuallyTaken = 0;
			cin >> subjects >> minToBeTaken;
			for (int b = 0; b < subjects; b++) {
				string temp;
				cin >> temp;
				if (takenCourses.find(temp) != takenCourses.end()) {
					actuallyTaken++;
				}
			}
			if (actuallyTaken < minToBeTaken) {
				pass = false;
			}
		}		
		cout << ((pass) ? "yes" : "no") << endl;
		takenCourses.clear();
		getline(cin, str);
	}
	return 0;
}
