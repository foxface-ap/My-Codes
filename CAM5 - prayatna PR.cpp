#include <bits/stdc++.h>

using namespace std;

vector <int> v[100010];
bool visited[100010];

void dfs(int sr)
{
    visited[sr] = false;

    for(int i=0;i<v[sr].size();i++)
    {
        if(visited[v[sr][i]])
            dfs(v[sr][i]);
    }
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        for(int i=0;i<100010;i++)
        {
            v[i].clear();
            visited[i] = true;
        }

        int n;
        cin >> n;

        int e,x,y;
        cin >> e;

        for(int i=0;i<e;i++)
        {
            cin >> x >> y;

            v[x].push_back(y);
            v[y].push_back(x);
        }

        int count = 0;

        for(int i=0;i<n;i++)
        {
            if(visited[i])
            {
                dfs(i);
                count++;
            }
        }

        cout << count << endl;
    }
}