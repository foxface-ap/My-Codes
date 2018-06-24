#include <bits/stdc++.h>

using namespace std;

int dp[6101][6101];

int solve(string s, int start, int end)
{
	if(dp[start][end] == -1)
	{
		if(start >= end)
			dp[start][end] = 0;
		else if(s[start] == s[end])
			dp[start][end] = solve(s,start+1,end-1);
		else
			dp[start][end] = min(solve(s,start,end-1),solve(s,start+1,end))+1;
	}

	return dp[start][end];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
	{
		string s;
		cin >> s;

		int k = s.size();

		for(int i=0;i<=k;i++)
			dp[i][0] = dp[0][i] = 0;

		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=k;j++)
			{
				if(s[k-i] == s[j-1])
					dp[i][j] = dp[i-1][j-1]+1;
				else
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}

		cout << k - dp[k][k] << endl;
	}
	return 0;
}