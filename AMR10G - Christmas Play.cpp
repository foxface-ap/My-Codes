#include <bits/stdc++.h>

#define m 1000000007
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mk make_pair
#define sf(x) scanf("%d",&x)
#define pf(x) printf("%d",x)

using namespace std;

int a[100010];

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n,k;
        cin >> n >> k;

        int min = 1e9 + 7;

        for(int i=0;i<n;i++)
            cin >> a[i];
        
        sort(a,a+n);

        for(int i=0;i<=n-k;i++)
        {
            if(min > (a[i+k-1]-a[i]))
                min = a[i+k-1] - a[i];
        }

        cout << min << endl;
    }
}