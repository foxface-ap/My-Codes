#include <bits/stdc++.h>

using namespace std;

vector <int> v[10010];

bool node[100010];

void dfs(int s) 
{
    node[s] = true;

    for(int i = 0;i < v[s].size();++i)
    {
         if(node[v[s][i]] == false)
             dfs(v[s][i]);
    }
}

int main()
{
	int n,m,x,y,count=0;
	cin >> n >> m;

	for(int i=0;i<n;i++)
		node[i] = false;

	for(int i=0;i<m;i++)
	{
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	for(int i = 1;i <= n;++i) 
	{
        if(node[i] == false)     
        {
            dfs(i);
            count++;
        }
    }

    if(count == 1 && n == (m+1))
    	cout << "YES" << endl;
    else
    	cout << "NO" << endl;
}