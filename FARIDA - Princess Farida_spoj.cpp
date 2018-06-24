#include <bits/stdc++.h>

#define ll long long

using namespace std;

int a[100010];
ll int dp[100010];

ll int solve(int a[],int start, int end)
{
	if(dp[start] == -1)
	{
		if(start > end)
			dp[start] = 0;

		if(start == end)
			dp[start] = a[start];
		if(start < end)
		{
			ll int p1 = solve(a,start+1,end);
			ll int p2 = a[start]+solve(a,start+2,end);

			dp[start] = max(p1,p2);
		}
	}
	
	return dp[start];
}

int main()
{
	int t;
	cin >> t;

	for(int j=1;j<=t;j++)
	{
		int n;
		cin >> n;

		for(int i=0;i<=n;i++)
			dp[i] = -1;

		for(int i=0;i<n;i++)
			cin >> a[i];

		cout << "Case " << j << ": " << solve(a,0,n-1) << endl;
	}
}