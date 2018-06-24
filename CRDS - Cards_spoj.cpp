#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		ll int n;
		cin >> n;

		cout << (n*(3*n+1)/2)%1000007 << endl;
	}
}