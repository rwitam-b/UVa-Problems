#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--) {
		int farmers, budget = 0;
		scanf("%d", &farmers);
		while (farmers--) {
			int land, animals, P;
			scanf("%d %d %d", &land, &animals, &P);
			budget += (land*P);
		}
		cout << budget << endl;
	}
	return 0;
}
