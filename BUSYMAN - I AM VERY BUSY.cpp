#include <bits/stdc++.h>

#define pb push_back
#define mk make_pair

using namespace std;

int main()
{
    int t,x,y;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector < pair<int,int> > v;

        for(int i=0;i<n;i++)
        {
            cin >> x >> y;
            v.pb(mk(y,x));
        }

        sort(v.begin(),v.end());

        int count = 0,temp = -1;

        for(int i=0;i<n;i++)
        {
            //cout << v[i].first << " " << v[i].second << endl;

            if(v[i].second >= temp)
            {
                count++;
                temp = v[i].first;
            }
        }

        cout << count << endl;
    }
}