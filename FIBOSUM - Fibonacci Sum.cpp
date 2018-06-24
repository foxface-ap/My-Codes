#include <bits/stdc++.h>

#define m 1000000007
#define ll long long

using namespace std;

map <ll int,ll int> f;

ll int fib(ll int n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
    {
        f[n] = 1;
        return f[n];
    }
 
    if (f[n])
        return f[n];
 
    ll int k = (n & 1)? (n+1)/2 : n/2;

    f[n] = (n & 1)? ((fib(k)%m * fib(k)%m)%m + (fib(k-1)%m * fib(k-1)%m)%m)%m 
                : (((2*fib(k-1))%m + fib(k)%m)%m * fib(k)%m)%m;
 
    return f[n]%m;
}

int main()
{
    ll int t;
    cin >> t;

    while(t--)
    {
        int x,y;
        cin >> x >> y;

        cout << ((fib(x)%m * fib(y-x+1)%m)%m + (fib(x+1)%m * (fib(y-x+2)-1)%m)%m)%m << endl;
    }

    /*while(t--)
    {
        ll int n;
        cin >> n;

        cout << fib(n) << endl;
    }*/
}