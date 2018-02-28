#include<iostream>
#include<string>
#include<sstream>
#include<vector>


using namespace std;

int main() {
	int count = 1;
	string str;
	stringstream ss;
	while (getline(cin, str) && !str.empty()) {
		ss = stringstream(str);
		vector<int> signals;
		int seconds = 100;
		while (ss.good()) {
			int temp;
			ss >> temp;
			signals.push_back(temp);
			if (temp < seconds) {
				// calculating minimum cycle time
				seconds = temp;
			}
		}
		bool *status = new bool[signals.size()];
		bool search = true;

		// Simulating procedure for each second till 1 hour 1 sec
		for (; seconds <= 3601 && search; seconds++) {
			for (int a = 0; a < signals.size(); a++) {
				int factor = seconds % (2 * signals[a]);
				if (factor >= 0 && factor < signals[a] - 5) {
					status[a] = true;
				}
				else {
					status[a] = false;
				}
			}
			search = false;
			for (int a = 0; a < signals.size(); a++) {
				if (!status[a]) {
					search = true;
					break;
				}
			}
		}
		seconds--;
		cout << "Set " << count++;
		if (seconds > 3600) {
			cout << " is unable to synch after one hour." << endl;
		}
		else {
			int minutes = seconds / 60;
			seconds %= 60;
			cout << " synchs again at " << minutes << " minute(s) and " << seconds << " second(s) after all turning green." << endl;
		}
		delete status;
		signals.clear();
	}
	return 0;
}
