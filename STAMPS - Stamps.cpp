#include <bits/stdc++.h>

#define ll long long

ll int a[1000010];

using namespace std;

int main()
{
	int t,j=1;
	cin >> t;

	while(t--)
	{
		ll int n,b;
		cin >> n >> b;

		for(int i=0;i<b;i++)
			cin >> a[i];

		sort(a,a+b);

		int count = 0;

		while(b--)
		{
			n -= a[b];
			count++;

			if(n <= 0)
				break;
		}

		cout << "Scenario #" << j << ":" << endl;

		if(n > 0)
			cout << "impossible" << endl;
		else
			cout << count << endl;

		j++;
	}
}