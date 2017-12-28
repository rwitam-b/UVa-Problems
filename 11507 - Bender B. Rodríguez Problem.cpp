#define axis(str) str[str.size()-1]
#define sign(str) str[0]
#include<iostream>
#include<string>

using namespace std;

int main()
{
	int length;
	string bend;
	while (cin >> length && length > 1) {
		string pos = "+x";
		for (int a = 0; a < length - 1; a++) {
			cin >> bend;
			if (!bend.compare("No")) {
				continue;
			}
			if (axis(pos) == 'x') {
				if (sign(pos) == '+') {
					pos = bend;
				}
				else {
					pos[0] = (sign(bend) == '+' ? '-' : '+');
					pos[1] = axis(bend);
				}
			}
			else if (axis(pos) == 'y' && axis(bend) == 'y') {
				if (sign(pos) == '+') {
					pos = (sign(bend) == '+' ? "-x" : "+x");
				}
				else {
					pos = (sign(bend) == '+' ? "+x" : "-x");
				}
			}
			else if (axis(pos) == 'z' && axis(bend) == 'z') {
				if (sign(pos) == '+') {
					pos = (sign(bend) == '+' ? "-x" : "+x");
				}
				else if (sign(pos) == '-') {
					pos = (sign(bend) == '+' ? "+x" : "-x");
				}
			}
		}
		cout << pos << endl;
	}
	return 0;
}
