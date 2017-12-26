#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
	int c1, c2;
	while (scanf("%d %d", &c1, &c2) && (c1 != -1 && c2 != -1)) {
		int change = 0;
		change = (c2 > c1) ? (c2 - c1) : (c1 - c2);
		if (change > 50) {
			change = 100 - change;
		}
		cout << change << endl;
	}
	return 0;
}
