#include <bits/stdc++.h>

using namespace std;

vector <int> v[100010];

int traverse(int node,int prev)
{
    int max = 0;

    if(v[node].size() == 1 && v[node][0] == prev)
        return 0;

    for(int i=0;i<v[node].size();i++)
    {
        if(v[node][i] != prev)
        {
            int temp = traverse(v[node][i],node);

            if(temp > max)
                max = temp;
        }
    }

    return max+1;

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
    }

    vector <int> v1;

    for(int i=0;i<v[1].size();i++)
    {
        int temp = traverse(v[1][i],1);

        v1.push_back(temp);
    }

    sort(v1.begin(), v1.end());
    if(n == 1)
        cout << 0 << endl;
    else if(v1.size() == 1)
        cout << v1[v1.size()-1]+1 << endl;
    else
        cout << v1[v1.size()-1] + v1[v1.size()-2] + 2 << endl;
}