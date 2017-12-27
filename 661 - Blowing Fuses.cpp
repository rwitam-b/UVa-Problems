#include<algorithm>
#include<iostream>

using namespace std;

int calculatePower(int devices, bool *state, int *wattage) {
	int power = 0;
	for (int a = 0; a < devices; a++) {
		if (state[a]) {
			power += wattage[a];
		}
	}
	return power;
}

int main()
{
	int sequence = 1, devices, operations, capacity;
	while (cin >> devices >> operations >> capacity && (devices || operations || capacity)) {
		bool *device = new bool[devices];
		int *wattage = new int[devices];
		int maxPower = 0;
		bool fuse = true;
		for (int a = 0; a < devices; a++) {
			device[a] = false;
		}
		for (int a = 0; a < devices; a++) {
			cin >> wattage[a];
		}
		for (int a = 0; a < operations; a++) {
			int temp, statePower;
			cin >> temp;
			device[temp - 1] = !device[temp - 1];
			statePower = calculatePower(devices, device, wattage);
			if (statePower > capacity) {
				fuse = false;
			}
			maxPower = max(maxPower, statePower);
		}
		cout << "Sequence " << sequence++ << endl;
		if (fuse) {
			cout << "Fuse was not blown." << endl << "Maximal power consumption was " << maxPower << " amperes." << endl;
		}
		else {
			cout << "Fuse was blown." << endl;
		}
		cout << endl;
		delete[]device;
		delete[]wattage;
	}
	return 0;
}
