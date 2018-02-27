#include<iostream>
#include<sstream>
#include<unordered_map>


using namespace std;

struct arr {
	int base_addr, size_of_element, dimensions;
	int *lower_bounds, *upper_bounds;
};

struct arr *memory;

int C(struct arr copy, int index) {
	if (index == 0) {
		int retVal = copy.base_addr;
		for (int a = 1; a <= copy.dimensions; a++) {
			retVal -= C(copy, a)*copy.lower_bounds[a - 1];
		}
		return retVal;
	}
	else if (index == copy.dimensions) {
		return copy.size_of_element;
	}
	else {
		return C(copy, index + 1)*(copy.upper_bounds[index] - copy.lower_bounds[index] + 1);
	}
}

int main() {
	int N, R;
	string str;
	stringstream ss;
	unordered_map<string, int> lookup;
	cin >> N >> R;
	memory = new struct arr[N];
	getline(cin, str);
	for (int a = 0; a < N; a++) {
		getline(cin, str);
		ss = stringstream(str);
		ss >> str;
		lookup[str] = a;
		ss >> memory[a].base_addr;
		ss >> memory[a].size_of_element;
		ss >> memory[a].dimensions;
		memory[a].lower_bounds = new int[memory[a].dimensions];
		memory[a].upper_bounds = new int[memory[a].dimensions];
		for (int b = 0; b < memory[a].dimensions; b++) {
			ss >> memory[a].lower_bounds[b];
			ss >> memory[a].upper_bounds[b];
		}
	}
	for (int a = 0; a < R; a++) {
		getline(cin, str);
		ss = stringstream(str);
		ss >> str;
		cout << str << "[";
		int location = lookup[str];
		int result = C(memory[location], 0);
		for (int b = 1; b <= memory[location].dimensions; b++) {
			if (b != 1) {
				cout << ", ";
			}
			int temp;
			ss >> temp;
			cout << temp;
			result += C(memory[location], b)*temp;
		}
		cout << "] = " << result << endl;
	}
	for (int a = 0; a < N; a++) {
		delete memory[a].lower_bounds;
		delete memory[a].upper_bounds;
	}
	delete memory;
	return 0;
}
