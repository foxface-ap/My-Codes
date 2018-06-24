#include <bits/stdc++.h>

using namespace std;

int dp[1010][1010];
int a[1010];

int solve(int st, int ed)
{
    if(st > ed)
        return 0;

    if(dp[st][ed] == -1)
    {
        int temp1,temp2;

        temp1 = a[st] + (a[st+1] >= a[ed] ? solve(st+2,ed) : solve(st+1,ed-1));

        temp2 = a[ed] + (a[st] >= a[ed-1] ? solve(st+1,ed-1) : solve(st,ed-2));

        dp[st][ed] = max(temp1,temp2);
    }

    return dp[st][ed];
}

int main()
{
    int k = 0;

    while(true)
    {
        k++;

        int n;
        cin >> n;

        if(n == 0)
            return 0;

        int sum = 0;

        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            sum += a[i];
        }

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
                dp[i][j] = -1;
        }

        printf("In game %d, the greedy strategy might lose by as many as %d points.\n",k,2*solve(0,n-1)-sum);
    }
}