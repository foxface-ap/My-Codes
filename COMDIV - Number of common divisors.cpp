#include <bits/stdc++.h>
 
using namespace std;

int a[1000010];

void solve()
{
    for(int i=1;i<1000010;i++)
    {
        if(i%2)
            a[i] = 1;
        else
            a[i] = 2;
    }

    int j = 3;

    while(j < 500010)
    {
        for(int i=j;i<1000010;i+=j)
        {
            if(i%j == 0)
                a[i]++;
        }

        j++;
    }
}

int main()
{
	int t;
	scanf("%d",&t);

    solve();
 
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);

		printf("%d\n",a[__gcd(n,m)]);
	}
}