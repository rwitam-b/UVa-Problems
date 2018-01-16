#include<iostream>
#include<string>
#define getDigits(x) to_string(x).size()

using namespace std;

int main()
{
	string str;
	long long int num, num2, count;
	while (getline(cin, str) && str.compare("END")) {
		num = (str.size() <= 3) ? stoi(str) : 0;
		num2 = str.size();
		count = 1;
		while (num!=num2) {
			count++;
			num = num2;
			num2 = getDigits(num2);
		}
		cout << count << endl;
	}
	return 0;
}
