#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;
ll int a[100010],dp[100010];

ll int solve(int st)
{
    if(st > (n-1))
        return 0;

    if(dp[st] == -1)
    {
        int t = n - st -1;

        ll int t1,t2,t3;
        t1 = t2 = t3 = -1;

        if(t >= 0)
            t1 = a[st] + solve(st+2);
        if(t >= 1)
            t2 = a[st] + a[st+1] + solve(st+4);
        if(t >= 2)
            t3 = a[st] + a[st+1] + a[st+2] + solve(st+6); 

        dp[st] = max(t1,max(t2,t3));
    }

    return dp[st];
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i=0;i<n;i++)
            cin >> a[i];

        for(int i=0;i<=n;i++)
            dp[i] = -1;

        cout << solve(0) << endl;
    }
}