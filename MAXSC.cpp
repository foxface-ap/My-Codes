#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n,x;
		cin >> n;

		vector <int> v[n];

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin >> x;
				v[i].push_back(x);
			}

			sort(v[i].begin(),v[i].end(),greater<int>());
		}

		ll int sum = 0,max=1000000007;
		bool flag;
		x = n;

		while(x--)
		{
			flag = true;

			for(int i=0;i<n;i++)
			{
				if(v[x][i] < max)
				{
					sum += v[x][i];
					max = v[x][i];
					flag = false;
					break;
				}
			}

			if(flag)
				break;
		}

		if(flag)
			cout << -1 << endl;
		else
			cout << sum << endl;
	}
}
