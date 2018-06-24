#include <bits/stdc++.h>

using namespace std;

int a[100000];

int main()
{
	int t;
	cin >> t;

	while(t != -1)
	{
		int count = 0;

		for(int i=0;i<t;i++)
		{
			cin >> a[i];
			count += a[i];
		}

		if(__gcd(count,t) != t)
			cout << -1 << endl;
		else
		{
			count /= t;

			int ans = 0;

			for(int i=0;i<t;i++)
			{
				if(a[i] < count)
					ans += (count-a[i]);
			}

			cout << ans << endl;
		}

		cin >> t;
	}
}