#include<iostream>
#include<string>

using namespace std;

int main()
{
	int height, width;
	while (cin >> height && height > 0 && cin >> width) {
		int laserCuts = 0;
		int prev, next;
		cin >> prev;
		laserCuts += height - prev;
		for (int a = 1; a < width; a++) {
			cin >> next;
			if (next < prev) {
				laserCuts += prev - next;
			}
			prev = next;
		}
		cout << laserCuts << endl;
	}
	return 0;
}
