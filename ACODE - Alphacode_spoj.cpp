#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll int dp[5050];

ll int solve(string s, int start, int end)
{
	if(s.size() == 0)
		return 1;

	if(dp[start] = -1)
	{
		if(start >= end)
			dp[start] = 1;
		else
		{
			int temp;
			temp = s[start] - '0';
			temp *= 10;
			temp += s[start+1] - '0';

			if(temp <= 26 && temp > 0)
				dp[start] = solve(s,start+1,end) + solve(s,start+2,end);
			else
				dp[start] = solve(s,start+1,end);
		}
	}

	return dp[start];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	while(s != "0")
	{
		int k = s.size();

		memset(dp, 0, 5050*sizeof(dp[0]));

		ll int ans = 1;

		dp[k] = 1;

		while(k--)
		{
			if(s[k] == '0')
			{
				ans *= dp[k+1];
				dp[k] = 0;
				dp[--k] = 1;
			}
			else
			{
				int temp;
				temp = s[k] - '0';
				temp *= 10;
				temp += s[k+1] - '0';

				if(temp <= 26 && temp > 0)
					dp[k] = dp[k+1] + dp[k+2];
				else
					dp[k] = dp[k+1];
			}
		}

		ans *= dp[0];

		cout << ans << endl;

		cin >> s;
	}
}