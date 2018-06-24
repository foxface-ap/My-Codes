#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool a[100010];

int main()
{
	for(int i=0;i<100000;i++)
		a[i] = true;

	for(int i=2;i<100000;i++)
	{
		if(a[i] == true)
		{
			for(int j=2*i;j<100000;j+=i)
				a[j] = false;
		}
	}

	ll int t;
	scanf("%lld",&t);

	while(t--)
	{
		ll int n,m,start;
		scanf("%lld%lld",&m,&n);

		set <ll int> s;

		for(int i=2; i<100000 && i <= n;i++)
		{
			if(a[i] == true)
			{
				if(i >= m)
					start = 2*i;
				else
					start = (m - (m%i))%i;

				for(int j = start; j<=n ;j += i)
					s.insert(j);
			}
		}

		for(int i=m;i<=n;i++)
		{
			if(s.count(i) == 0 && i != 1)
				printf("%lld\n",i);
		}
	}
}