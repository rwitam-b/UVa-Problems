#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
	int count = 1, T;
	scanf("%d", &T);
	while (T--) {
		int N, wall, temp, low=0, high=0;
		scanf("%d", &N);
		scanf("%d", &wall);
		while (--N) {
			scanf("%d", &temp);
			if (temp > wall) {
				high++;
			}
			else if (temp < wall) {
				low++;
			}
			wall = temp;
		}
		cout << "Case " << count++ << ": " << high << " " << low << endl;
	}
	return 0;
}
