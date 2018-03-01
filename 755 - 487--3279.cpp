#include<iostream>
#include<string>
#include<unordered_map>
#include<map>
#include<algorithm>

using namespace std;

unordered_map<char, int> T9;

// Setting up the T9 character set mapping
void setupT9() {
	int count = 1, map = 2;
	for (char c = 'A'; c < 'Z'; c++, count++) {
		if (c == 'Q') {
			count--;
			continue;
		}
		T9[c] = map;
		if (count % 3 == 0) {
			map++;
		}
	}
}

// Function to normalize the phone number
string normalize(string number) {
	string output = "";
	for (int a = 0; a < number.size(); a++) {
		if (number[a] >= '0' && number[a] <= '9') {
			output += number[a];
		}
		else if (number[a] >= 'A' && number[a] < 'Z') {
			output += '0' + T9[number[a]];
		}
	}
	output.insert(3, "-");
	return output;
}

int main() {
	int datasets;
	setupT9();
	string str;
	cin >> datasets;
	getline(cin, str);
	getline(cin, str);
	while (datasets--) {
		int directoryLength;
		cin >> directoryLength;
		getline(cin, str);
		map<string, int> directory;
		for (int a = 0; a < directoryLength; a++) {
			getline(cin, str);
			transform(str.begin(), str.end(), str.begin(), ::toupper);
			str = normalize(str);
			if (directory.find(str) != directory.end()) {
				directory[str] += 1;
			}
			else {
				directory[str] = 1;
			}
		}
		bool flag = false;
		for (auto number : directory) {
			if (number.second > 1) {
				cout << number.first << " " << number.second << endl;
				flag = true;
			}
		}
		if (!flag) {
			cout << "No duplicates." << endl;
		}
		if (datasets > 0) {
			cout << endl;
		}
		getline(cin, str);
	}
	return 0;
}
