#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
	int p;
	cin >> p;

	while(p--)
	{
		ll int n;
		cin >> n;

		ll int t;

		ll int sum = 0;

		//sum = n*(n+1)*(n+2)/6;

		t = n/2;

		if(n%2==0)
			sum += t*(t+1)*(4*t-1)/6;
		else
			sum += t*(t+1)*(4*t+5)/6;

		cout << sum << endl;
	}
}