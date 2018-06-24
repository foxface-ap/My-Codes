#include <bits/stdc++.h>

using namespace std;

int a[1000100];
int _min = 0;

bool solve1(int n, int c, int val)
{
    int count = 1,book = 0;

    for(int i=1;i<n;i++)
    {
        if((a[i]-a[book]) >= val)
        {
            count++;
            book = i;
        }
    }

    if(count >= c)
        return true;
    else
        return false;
}

void solve(int n, int c, int st, int ed)
{
    int mid = (st+ed)/2;

    if(st >= ed)
        return;
    
    if(solve1(n,c,mid))
    {
        if(_min < mid)
            _min = mid;

        solve(n,c,mid+1,ed);
    }   
    else
        solve(n,c,st,mid);
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n,c;
        cin >> n >> c;

        for (int i = 0; i < n; i++)
            cin >> a[i];

        _min = 0;

        sort(a,a+n);

        if(c <= 1)
        {
            cout << a[n-1] << endl;
            continue;
        }

        solve(n,c,0,a[n-1]+1);

        cout << _min << endl;
    }
}