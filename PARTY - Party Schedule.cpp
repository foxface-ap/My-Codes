#include <bits/stdc++.h>

#define mk make_pair

using namespace std;

pair <int,int> p[10000];

pair <int,int> dp[1010][1010];

pair <int,int> solve(int st, int ed, int w)
{
    if(st > ed)
        return mk(0,0);
    
    if(dp[st][w].first == -1)
    {
        if((w-p[st].first) < 0)
            dp[st][w] = solve(st+1,ed,w);
        else
        {
            pair <int,int> p1,p2;

            p1 = solve(st+1,ed,w);
            p2 = solve(st+1,ed,w-p[st].first);

            p2.first += p[st].first;
            p2.second += p[st].second;

            if(p1.second == p2.second)
            {
                if(p1.first < p2.first)
                    dp[st][w] = p1;
                else
                    dp[st][w] = p2;
            }
            else if(p1.second > p2.second)
                dp[st][w] = p1;
            else
                dp[st][w] = p2;
        }
    }

    return dp[st][w];
}

int main()
{
    int w,n,x,y;
    cin >> w >> n;

    while(w != 0 || n != 0)
    {    
        for(int i=0;i<1010;i++)
        {
            for(int j=0;j<1010;j++)
                dp[i][j] = mk(-1,-1);
        }

        for(int i=0;i<n;i++)
        {
            cin >> x >> y;
            p[i] = mk(x,y);
        }

        pair <int,int> p1 = solve(0,n-1,w);

        cout << p1.first << " " << p1.second << endl;

        cin >> w >> n;
    }
}