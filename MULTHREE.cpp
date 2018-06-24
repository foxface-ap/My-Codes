#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		ll int k,d1,d2;
		scanf("%lld %lld %lld",&k,&d1,&d2);

		ll int temp = (d1+d2)%10;

		ll int count1 = d1+d2;

		ll int count = 0,j=2;

		bool flag = false;

		while(temp != 2 && k > j)
		{
			if(temp == 0)
			{
				flag = true;
 				break;
			}

			count1 += temp;

			temp = (2*temp)%10;

			j++;
		}

		if(flag)
		{
			if(count1%3 == 0)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
		{
			k -= j;

			temp = k/4;

			count += temp*20;

			temp = k%4;

			if(temp == 1)
				count += 2;
			if(temp == 2)
				count += 6;
			if(temp == 3)
				count += 14;

			count += count1;

			if(count%3 == 0)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}