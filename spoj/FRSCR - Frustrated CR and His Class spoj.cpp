#include <bits/stdc++.h>

using namespace std;

int a[110],b[110];
int p,n,m,ans;

int solve(int x[],int n,int p)
{
    int ans1 = 0;
    int temp;

    for(int i=0;i<n;i++)
    {
        temp = sqrt(2.0*p/x[i]);

        while((2*p - x[i]*temp*(temp+1)) < 0)
            temp--;

        ans1 += temp;
    }

    //cout << ans1 << " " << p << endl;

    return ans1;
}

void solve1(int st, int ed)
{
    int ans1,ans2,mid;

    if(st == (ed-1))
    {
        solve1(st,st);
        solve1(ed,ed);

        return;
    }

    mid = (st+ed)/2;

    ans1 = solve(a,n,mid);
    ans2 = solve(b,m,p-mid);

    if(st == ed)
    {
        if(ans1 <= ans2 && ans1 > ans)
            ans = ans1;
        
        return;
    }

    if(ans1 > ans2)
        solve1(st,mid);
    else
    {
        if(ans1 > ans)
            ans = ans1;

        solve1(mid,ed);
    }
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        cin >> p >> n >> m;

        for(int i=0;i<n;i++)
            cin >> a[i];

        for(int i=0;i<m;i++)
            cin >> b[i];

        ans = 0;

        solve1(0,p);

        cout << ans << endl;
    }
}