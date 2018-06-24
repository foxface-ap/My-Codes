#include <bits/stdc++.h>

#define ma 1000000000

using namespace std;

pair <int,int> a[10010];
int dp[10010];

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int e,f;
        cin >> e >> f;

        int n;
        cin >> n;

        for(int i=0;i<n;i++)
            cin >> a[i].second >> a[i].first;

        sort(a,a+n);

        dp[0] = 0;

        for(int i=1;i<=f-e;i++)
        {
            dp[i] = ma;

            for(int j=0;j<n;j++)
            {
                if(i >= a[j].first)
                    dp[i] = min(dp[i],a[j].second+dp[i-a[j].first]);
                else
                    break;
            }
        }

        if(dp[f-e] == ma)
            cout << "This is impossible." << endl;
        else
            cout << "The minimum amount of money in the piggy-bank is " << dp[f-e] << "." << endl;
    }
}