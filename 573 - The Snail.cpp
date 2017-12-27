#include<iostream>

using namespace std;

int main()
{
	int height, climb, slideDistance, fatigue;
	while (cin >> height >> climb >> slideDistance >> fatigue && height) {
		float initial = 0.0, dynamicClimb = climb;
		int day = 0;
		while (initial >= 0.0) {
			day++;
			initial += dynamicClimb;
			if (initial > height) {
				break;
			}
			initial -= slideDistance;
			dynamicClimb -= climb * (fatigue / 100.0);
			dynamicClimb = (dynamicClimb < 0) ? 0 : dynamicClimb;
		}
		if (initial <= 0) {
			cout << "failure on day " << day << endl;
		}
		else {
			cout << "success on day " << day << endl;
		}
	}
	return 0;
}
