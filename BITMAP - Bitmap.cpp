#include <bits/stdc++.h>

using namespace std;

int dis[200][200];
char a[200][200];

void bfs(int sr1, int sr2)
{
    queue <int> q;

    q.push(sr1);
    q.push(sr2);

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        int y = q.front();
        q.pop();

        int di = dis[x][y]+1;

        int d1[4] = {0,0,1,-1};
        int d2[4] = {1,-1,0,0};

        for(int i=0;i<4;i++)
        {
            x += d1[i];
            y += d2[i];

            if(di < dis[x][y])
            {
                q.push(x);
                q.push(y);

                dis[x][y] = di;
            }

            x -= d1[i];
            y -= d2[i];
        }
        
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

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin >> a[i][j];

                if(a[i][j] == '1')
                    dis[i][j] = 0;
                else
                    dis[i][j] = 100000000;
            }
        }

        for(int i=0;i<=(m+1);i++)
            dis[0][i] = dis[n+1][i] = 0;

        for(int i=0;i<=(n+1);i++)
            dis[i][0] = dis[i][m+1] = 0;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i][j] == '1')
                    bfs(i,j);
            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i][j] == '1')
                    bfs(i,j);
            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                cout << dis[i][j] << " ";
            cout << endl;
        }
    }
}