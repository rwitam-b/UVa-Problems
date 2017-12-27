#include<iostream>
#include<string>
#include<limits>

using namespace std;

int main()
{
	int RFP = 1, n, p;
	string str;
	while (cin >> n >> p && (n || p)) {
		getline(cin, str);
		for (int a = 0; a < n; a++) {
			getline(cin, str);
		}
		string potential;
		int maxMet = 0, minPrice = numeric_limits<double>::max();
		for (int a = 0; a < p; a++) {
			double price;
			int met;
			getline(cin, str);
			cin >> price >> met;			
			if (met == maxMet && price < minPrice) {
				minPrice = price;
				potential = str;
			}
			if (met > maxMet) {
				maxMet = met;
				minPrice = price;
				potential = str;
			}
			getline(cin, str);
			for (int b = 0; b < met; b++) {
				getline(cin, str);
			}
		}
		if (RFP > 1) {
			cout << endl;
		}
		cout << "RFP #" << RFP++ << endl << potential << endl;
	}
	return 0;
}
