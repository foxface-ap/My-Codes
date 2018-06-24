    #include <bits/stdc++.h>
    #define ll long long

    using namespace std;

    ll int solve(ll int a)
    {
        if(a/10 == 0)
            return a;

        ll int sum = 0;

        while(a != 0)
        {
            ll int temp = a%10;
            sum += temp;
            a /= 10;
        }

        return solve(sum);
    }
     
    ll int fact(ll int a, ll int n)
    {
        ll int temp = n/10;
        if(temp == 0)
            return solve(pow(a,n));

        if(n%2 == 0)
            return solve(fact(a,n/2)*fact(a,n/2));
        else
            return solve(fact(a,n/2)*fact(a,n/2+1));
    }

    int main()
    {
        int t;
        cin >> t;

        while(t--)
        {
            ll int a,n;
            cin >> a >> n;

            cout << fact(solve(a),n) << endl;
        }
    }