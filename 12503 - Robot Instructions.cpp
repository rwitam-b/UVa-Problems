#include<string>
#include<iostream>
#include<sstream>

using namespace std;

int main()
{
	int T;
	string command;
	stringstream ss;
	cin >> T;
	while (T--) {
		int temp, N;
		cin >> N;
		temp = 0;
		int *moves = new int[N];
		getline(cin, command);
		while (temp < N) {
			getline(cin, command);
			if (!command.compare("LEFT")) {
				moves[temp++] = -1;
			}
			else if (!command.compare("RIGHT")) {
				moves[temp++] = 1;
			}
			else {
				int commandN;
				ss = stringstream(command);
				ss >> command;
				ss >> command;
				ss >> commandN;
				moves[temp++] = moves[commandN - 1];
			}
		}
		temp = 0;
		for (int a = 0; a < N; a++) {
			temp += moves[a];
		}
		cout << temp << endl;
		delete[]moves;
	}
	return 0;
}
