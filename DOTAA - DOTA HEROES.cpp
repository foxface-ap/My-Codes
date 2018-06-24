#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n,m,d;
        cin >> n >> m >> d;

        int count = 0;

        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;

            if(x > d)
                count += x/d;

            if(x % d == 0)
                count--;
        }

        if(count >= m)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}