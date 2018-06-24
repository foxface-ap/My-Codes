#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		ll int count=0,n,x;
		cin >> n;

		for(int i=0;i<n;i++)
		{
			cin >> x;
			count += x;

			count %= n;
		}

		if(count%n == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}