#include <bits/stdc++.h>

using namespace std;

vector <int> v[100010];
bool mark[100010];

void bfs(int sr)
{
    queue <int> q;
    stack <int> q1;
    q.push(sr);
    q.push(0);
    q1.push(1);
    mark[sr] = false;

    int count = 0;

    while(!q.empty())
    {
        sr = q.front();
        q.pop();

        if(sr == 0)
        {
            if(!q.empty())
                q.push(0);
            //cout << count << endl;
            q1.push(count);
            count = 0;
            continue;
        }

        for(int i=0;i<v[sr].size();i++)
        {
            if(mark[v[sr][i]])
            {
                q.push(v[sr][i]);
                mark[v[sr][i]] = false;
                count++;
            }
        }
    }

    //cout << "aa" << endl;

    int temp1,temp2;
    temp1 = temp2 = 0;
    bool flag1 = true;

    while(!q1.empty())
    {
        sr = q1.top();
        //cout << sr << endl;
        q1.pop();

        if(flag1)
        {
            temp1 += sr;
            flag1 = false;
            continue;
        }

        temp2 += sr;
        flag1 = true;

    }

    cout << min(temp1,temp2) << endl;
}

int main()
{
    int n,x,y;
    cin >> n;

    for(int i=1;i<n;i++)
    {
        cin >> x >> y;

        v[x].push_back(y);
        v[y].push_back(x);

        mark[i] = true;
    }

    mark[n] = true;

    if(n == 1)
        cout << 1 << endl;
    else
        bfs(1);

    return 0;
}