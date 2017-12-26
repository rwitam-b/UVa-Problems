#include<cmath>
#include<iostream>

using namespace std;

int main()
{
	int T, count = 1;
	cin >> T;
	while (T--) {
		int N, mCost = 0, jCost = 0;
		cin >> N;
		while (N--) {
			int temp;
			cin >> temp;
			mCost += (1 + (int)floor(temp / 30.0)) * 10;
			jCost += (1 + (int)floor(temp / 60.0)) * 15;
		}
		cout << "Case " << count++ << ": ";
		if (mCost < jCost) {
			cout << "Mile " << mCost << endl;
		}
		else if (jCost < mCost) {
			cout << "Juice " << jCost << endl;
		}
		else {
			cout << "Mile Juice " << mCost << endl;
		}
	}
	return 0;
}
