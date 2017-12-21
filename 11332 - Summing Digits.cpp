#include<cstdio>
#include<iostream>

using namespace std;

long long int sum(long long int num) {
	long long int total = 0;
	while (num) {
		total += (num % 10);
		num /= 10;
	}
	return total;
}

int main()
{
	long long int num;
	while (scanf("%lld", &num) && num) {
		long long int total = 0;
		while (num>9){
			total = sum(num);
			num = total;
		}
		cout << num << endl;
	}
	return 0;
}
