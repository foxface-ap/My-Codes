#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n,x;
        cin >> n;

        map <int,int> m;

        for(int i=0;i<n;i++)
        {
            cin >> x;
            m[x]++;
        }

        map <int,int> :: iterator it;

        bool flag = false;

        for(it=m.begin();it != m.end();it++)
        {
            if(it->second > ceil(n/2.0))
            {
                flag = true;
                break;
            }
        }

        if (flag)
            cout << "YES " << it->first << endl;
        else
            cout << "NO" << endl;
    }
}