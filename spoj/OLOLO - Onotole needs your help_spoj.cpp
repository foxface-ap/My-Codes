#include <bits/stdc++.h>

#define ll long long

using namespace std;

int a[1000010];

int main()
{
	int t;
	scanf("%d",&t);

	for(int i=0;i<t;i++)
		scanf("%d",&a[i]);

	sort(a,a+t);

	for(int i=0;i<t;i+=2)
	{
		if(a[i] != a[i+1])
		{
			printf("%d\n",a[i]);
			break;
		}
	}
}