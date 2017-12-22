#include<cstdio>
#include<iostream>
#include<sstream>

using namespace std;

int main()
{
	int N, B, H, W, W2, cost;
	bool flag = false;
	string str;
	stringstream s;
	while (getline(cin, str) && !str.empty()) {
		flag = false;
		s = stringstream(str);
		s >> N >> B >> H >> W;
		cost = B;
		while (H--) {
			int P, temp;
			bool accomodate = false;
			W2 = W;
			getline(cin, str);
			s = stringstream(str);
			s >> P;
			getline(cin, str);
			s = stringstream(str);
			while (W2--) {
				s >> temp;
				if (temp >= N) {
					accomodate = true;
					break;
				}
			}
			if (accomodate && ((N*P) < cost)) {
				cost = N * P;
				flag = true;
			}
		}
		if (flag) {
			cout << cost << endl;
		}
		else {
			cout << "stay home" << endl;
		}
	}
	return 0;
}
