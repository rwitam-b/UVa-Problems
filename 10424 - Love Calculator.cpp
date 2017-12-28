#include<algorithm>
#include<iostream>
#include<string>

using namespace std;

int sum(int num) {
	int total = 0;
	while (num) {
		total += (num % 10);
		num /= 10;
	}
	return total;
}

int calculateNameSum(string str) {
	int result = 0;
	for (int a = 0; a < str.size(); a++) {
		char temp = str[a];
		if (temp >= 'a' && temp <= 'z') {
			result += temp - 'a' + 1;
		}
		else if (temp >= 'A' && temp <= 'Z') {
			result += temp - 'A' + 1;
		}
	}
	while (result > 9) {
		result = sum(result);
	}
	return result;
}

int main()
{
	string name1, name2;
	while (getline(cin, name1) && !name1.empty() && getline(cin, name2)) {
		int val1 = calculateNameSum(name1), val2 = calculateNameSum(name2);
		float ratio = (float)min(val1, val2) / max(val1, val2);
		ratio *= 100;
		printf("%.2f %%\n", ratio);
	}

	return 0;
}
