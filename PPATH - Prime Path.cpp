#include <bits/stdc++.h>

using namespace std;

bool prime[10010];
bool mark[10010];
int dis[10010];

void bfs(int sr)
{
    queue <int> q;

    int l = 0;

    q.push(sr);
    mark[sr] = false;
    dis[sr] = l;

    while(!q.empty())
    {
        int node = q.front(),a[4];
        q.pop();

        int num = node;

        for(int i=3;i>=0;i--)
        {
            a[i] = num%10;
            num /= 10;
        }

        for(int i=0;i<4;i++)
        {
            for(int j=1;j<10;j++)
            {
                a[i] = (a[i] + j)%10;

                num = 0;

                for(int k=0;k<4;k++)
                    num = num*10 + a[k];

                if(prime[num] && num > 1000 && mark[num])
                {
                    q.push(num);
                    mark[num] = false;
                    
                    dis[num] = dis[node]+1;
                }

                a[i] = (a[i] + 10 - j)%10;
            }
        }
    }
}

int main()
{
    for(int i=0;i<10010;i++)
        prime[i] = true;

    for(int i=2;i<10010;i++)
    {
        if(prime[i])
        {
            for(int j = 2*i;j<10010;j+=i)
                prime[j] = false;
        }
    }

    int t;
    cin >> t;

    while(t--)
    {
        int n,m;
        cin >> n >> m;

        for(int i=0;i<10010;i++)
        {
            mark[i] = true;
            dis[i] = 100000000;
        }

        bfs(n);

        if(dis[m] == 100000000)
            cout << "Impossible" << endl;
        else
            cout << dis[m] << endl;
    }
}