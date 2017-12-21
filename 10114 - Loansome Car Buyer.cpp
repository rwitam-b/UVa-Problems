#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	int loan_duration,dep;
	double downpayment, loan, car, emi;
	while (scanf("%d", &loan_duration) && loan_duration > 0) {
		scanf("%lf %lf %d", &downpayment, &loan, &dep);	
		emi = loan / loan_duration;
		double dep_rates[101];
		memset(dep_rates, 0, sizeof(dep_rates));
    
    // Populating the depreciation rates array
		for (int a = 0; a < dep; a++) {
			int month;
			double rate;
			scanf("%d %lf", &month, &rate);
			dep_rates[month] = rate;
		}
		for (int a = 1; a <= loan_duration; a++) {
			if (dep_rates[a] == 0) {
				dep_rates[a] = dep_rates[a - 1];
			}
		}	
    
    // Simulating the calculation specified in the problem
		car = loan+downpayment;
		car -= (car*dep_rates[0]);
		for (int a = 0; a <= loan_duration; a++, car -= (car*dep_rates[a]), loan -= emi) {
			if (car > loan) {
				cout << a;
				if (a == 1) {
					cout << " month";
				}
				else {
					cout << " months";
				}
				cout << endl;
				break;
			}
		}
	}
	return 0;
}
