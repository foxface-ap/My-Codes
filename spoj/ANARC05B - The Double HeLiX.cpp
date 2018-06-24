#include <bits/stdc++.h>

using namespace std;

int a[100010],b[100010];
int dp1[100010],dp2[100010];
int n,m;

int solve(int st, int type)
{
    if(type == 1)
    {
        if(st >= n)
            return 0;

        if(dp1[st] == -1)
        {
            int temp1,temp2;
            temp1 = temp2 = -1000000000;

            temp1 = solve(st+1,1);

            if(binary_search(b,b+m,a[st]))
            {
                int temp = lower_bound(b,b+m,a[st]) - b;

                temp2 = solve(temp+1,2);
            }

            dp1[st] = a[st] + max(temp1,temp2);
        }

        return dp1[st];
    }
    else
    {
        if(st >= m)
            return 0;

        if(dp2[st] == -1)
        {
            int temp1,temp2;
            temp1 = temp2 = -1000000000;

            temp1 = solve(st+1,2);

            if(binary_search(a,a+n,b[st]))
            {
                int temp = lower_bound(a,a+n,b[st]) - a;

                temp2 = solve(temp+1,1);
            }

            dp2[st] = b[st] + max(temp1,temp2);
        }

        return dp2[st];
    }
}

int main()
{
    while(true)
    {
        cin >> n;

        if(n == 0)
            return 0;

        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            dp1[i] = -1;
        }
        
        cin >> m;

        for(int i=0;i<m;i++)
        {
            cin >> b[i];
            dp2[i] = -1;
        }

        dp1[n] = dp2[m] = -1;

        cout << max(solve(0,1),solve(0,2)) << endl;
    }
}