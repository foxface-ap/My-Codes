#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll int a[1000010];

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    ll int t;
    cin >> t;

    while(t--)
    {
        ll int n,u;
        cin >> n >> u;

        for(int i=0;i<n;i++)
            a[i] = 0;
        
        while(u--)
        {
            ll int x,y,z;
            cin >> x >> y >> z;

            a[x] += z;
            a[y+1] += -z;
        }

        for(int i=1;i<n;i++)
            a[i] += a[i-1];

        ll int q;
        cin >> q;

        while(q--)
        {
            ll int x;
            cin >> x;

            cout << a[x] << endl;
        }
    }
    return 0;
}
