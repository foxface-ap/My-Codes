#include <bits/stdc++.h>

using namespace std;

pair <int,int> dp[101][101];

pair <int,int> solve(int a[], int st, int ed)
{
    if(dp[st][ed].first == 1000000007)
    {    
        pair <int,int> temp;

        if(st >= ed)
            return make_pair(a[st],0);
        
        for(int j=st;j<ed;j++)
        {
            dp[st][j] = solve(a,st,j);
            //cout << dp[st][j].first << " " << dp[st][j].second << endl;
            dp[j+1][ed] = solve(a,j+1,ed);
            //cout << dp[j+1][ed].first << " " << dp[j+1][ed].second << endl;

            temp.first = (dp[st][j].first+dp[j+1][ed].first)%100;
            temp.second = dp[st][j].second+dp[j+1][ed].second+dp[st][j].first*dp[j+1][ed].first;

            if(dp[st][ed].second > temp.second)
                dp[st][ed] = temp;
        }
    }

    return dp[st][ed];
}

int main()
{
    int n;

    while(cin >> n)
    {
        int a[110];

        for(int i=0;i<=100;i++)
        {
            for(int j=0;j<=100;j++)
                dp[i][j] = make_pair(1000000007,1000000007);
        }

        for(int i=0;i<n;i++)
            cin >> a[i];

        cout << solve(a,0,n-1).second << endl;
    }
}