#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll int maxCrossSum(ll int a[], int l, int m, int h)
{
    ll int sum = 0;
    ll int ls = INT_MIN;
    for (int i = m; i >= l; i--)
    {
        sum = sum + a[i];
        if (sum > ls)
          ls = sum;
    }
 
    sum = 0;
    ll int rs = INT_MIN;

    for (int i = m+1; i <= h; i++)
    {
        sum = sum + a[i];
        if (sum > rs)
          rs = sum;
    }
 
    return ls + rs;
}
 
ll int maxSub(ll int a[], int l, int h)
{
   if (l == h)
     return a[l];
 
   int m = (l + h)/2;

   return max(maxSub(a, l, m), max(maxSub(a, m+1, h), maxCrossSum(a, l, m, h)));
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		ll int n,k;
		cin >> n >> k;

		ll int a[100100],b[200100];
		ll int sum1 = 0, sum2 = 0, sum = 0, temp = 0;

		for(int i=0;i<n;i++)
		{
			cin >> a[i];
			b[i] = a[i];
			sum += a[i];
		}

		for(int i=n;i<2*n;i++)
			b[i] = a[i-n];

		sum1 = maxSub(a,0,n-1);
		sum2 = maxSub(b,0,2*n-1);

		if(k == 1)
			cout << sum1 << endl;
		else if(k == 2)
			cout << sum2 << endl;
		else
			cout << max(k*sum , max(sum1,max(sum2,max(sum1+(k-1)*sum,sum2+(k-2)*sum)))) << endl;
	}
}
