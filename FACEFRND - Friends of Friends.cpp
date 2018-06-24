#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    vector <int> v;
    map <int,int> m;

    while(t--)
    {
        int x,n;
        cin >> x >> n;

        v.push_back(x);

        for(int i=0;i<n;i++)
        {
            cin >> x;

            m[x]++;
        }
    }

    int count = m.size();

    for(int i=0;i<v.size();i++)
    {
        if(m[v[i]] != 0)
            count--;
    }

    cout << count << endl;
}