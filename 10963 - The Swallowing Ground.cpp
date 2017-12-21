#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--) {
		int W, gap, n, s;
		bool flag = true;
		scanf("%d", &W);
		scanf("%d %d", &n, &s);
		gap = n - s;
		while (--W) {
			scanf("%d %d", &n, &s);
			if ((n - s) != gap) {
				flag = false;
			}
		}
		cout << ((flag) ? "yes" : "no") << endl;
    
    // Take care of the presentation carefully
		if (T) {
			cout << endl;
		}
	}
	return 0;
}
