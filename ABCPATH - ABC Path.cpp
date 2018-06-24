#include <bits/stdc++.h>

using namespace std;

int dp[55][55];
char a[55][55];

int solve(int x,int y,int count)
{
    if(dp[x][y] != -1)
        return dp[x][y];

    char temp = a[x][y];
    temp++;

    vector <int> v;

    v.push_back(count);

    if(a[x-1][y] == temp)
        v.push_back(solve(x-1,y,count+1));

    if(a[x-1][y-1] == temp)
        v.push_back(solve(x-1,y-1,count+1));

    if(a[x][y-1] == temp)
        v.push_back(solve(x,y-1,count+1));

    if(a[x+1][y+1] == temp)
        v.push_back(solve(x+1,y+1,count+1));

    if(a[x+1][y] == temp)
        v.push_back(solve(x+1,y,count+1));

    if(a[x-1][y+1] == temp)
        v.push_back(solve(x-1,y+1,count+1));

    if(a[x+1][y-1] == temp)
        v.push_back(solve(x+1,y-1,count+1));

    if(a[x][y+1] == temp)
        v.push_back(solve(x,y+1,count+1));

    int ans = 0;

    for(int i=0;i<v.size();i++)
        ans = max(ans,v[i]);

    dp[x][y] = ans;

    return ans;
}

int main()
{
    int h,w,k=1;
    cin >> h >> w;

    while(h != 0)
    {
        int ans = 0;

        for(int i=0;i<55;i++)
        {
            for(int j=0;j<55;j++)
            {
                a[i][j] = 'z';
                dp[i][j] = -1;
            }
        }

        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++)
                cin >> a[i][j];
        }

        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++)
            {
                if(a[i][j] == 'A')
                    ans = max(ans,solve(i,j,1));
            }
        }

        cout << "Case " << k << ": " << ans << endl;

        cin >> h >> w;
        k++;
    }
}