#include<iostream>
#include<string>

using namespace std;

int main()
{
	int T;
	string result;
	cin >> T;
	getline(cin, result);
	while (T--) {
		getline(cin, result);
		if (!result.compare("1") || !result.compare("4") || !result.compare("78")) {
			cout << "+";
		}
		else if (!result.compare(result.size()-2, 2, "35")) {
			cout << "-";
		}
		else if (result[0] == '9' && result[result.size() - 1] == '4') {
			cout << "*";
		}
		else if (!result.compare(0, 3, "190")) {
			cout << "?";
		}
		cout << endl;
	}
	return 0;
}
