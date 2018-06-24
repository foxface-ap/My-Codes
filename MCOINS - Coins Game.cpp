#include <bits/stdc++.h>

using namespace std;

bool dp[1000010];

void solve(int k,int l)
{
    int y = min(k,l);
    int z = max(k,l);

    for (int i=0;i<1000010;i++)
    {
        if (i < 1)
            dp[i] = false;
        else if (i < y)
            dp[i] = !dp[i-1];
        else if (i < z)
            dp[i] = !(dp[i-1] && dp[i-y]);
        else
            dp[i] = !(dp[i-1] && dp[i-y] && dp[i-z]);
    }
}

int main()
{
    int k,l,n,x;
    cin >> k >> l >> n;

    solve(k,l);

    for (int i=0;i<n;i++)
    {
        cin >> x;
        if(dp[x])
            cout << 'A';
        else
            cout << 'B';
    }
    cout << endl;
}