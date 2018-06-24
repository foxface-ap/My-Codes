#include <bits/stdc++.h>

using namespace std;

char a[1010][1010];
int ans;

int d1[4] = {0,0,1,-1};
int d2[4] = {1,-1,0,0};

void dfs(int x, int y,int par)
{
    if(par > ans)
        ans = par;

    a[x][y] = '#';

    int x1,y1;

    for(int i=0;i<4;i++)
    {
        x1 = x+d1[i];
        y1 = y+d2[i];

        if(a[x1][y1] == '.')
            dfs(x1,y1,par+1);
    }
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n,m;
        cin >> n >> m;

        int x,y;

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
                cin >> a[i][j];
        }

        for(int i=0;i<=(n+1);i++)
            a[0][i] = a[m+1][i] = '#';

        for(int i=0;i<=(m+1);i++)
            a[i][0] = a[i][n+1] = '#';

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i][j] == '.')
                {
                    x = i;
                    y = j;
                    break;
                }
            }
        }

        cout 

        ans = 0;

        dfs(x,y,0);

        cout << ans << endl;
    }
}