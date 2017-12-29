#include<iostream>
#include<string>

using namespace std;

int main()
{
	string road;
	int length;
	while (cin >> length && length > 0) {
		getline(cin, road);
		getline(cin, road);
		int lastFound, minDistance = road.size();
		for (int a = 0; a < road.size(); a++) {
			if (road[a] == 'R' || road[a] == 'D' || road[a] == 'Z') {
				lastFound = a;
				break;
			}
		}
		for (int a = 0; a < road.size(); a++) {
			char present = road[a];
			char last = road[lastFound];
			if (present != '.') {
				if (present == 'Z') {
					minDistance = 0;
					break;
				}
				else if (present != last) {
					int dist = a - lastFound;
					if (dist < minDistance) {
						minDistance = dist;
					}
				}
				lastFound = a;
			}
		}
		cout << minDistance << endl;
	}
	return 0;
}
