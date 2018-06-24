#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
	int t;
	cin >> t;

	for(int i=1;i<=t;i++)
	{
		ll int r;
		cin >> r;

		double temp = 4.0*r*r + 1.0/4;

		printf("Case %d: %0.2f\n",i,temp);
	}
}