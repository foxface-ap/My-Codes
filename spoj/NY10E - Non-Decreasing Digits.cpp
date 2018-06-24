#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        cout << n << " ";

        int m;
        cin >> m;

        ll int d[10] = {1,1,1,1,1,1,1,1,1,1};

        while(m--)
        {
            for(int i=1;i<10;i++)
                d[i] += d[i-1];
        }

        cout << d[9] << endl;
    }
}