    #include <bits/stdc++.h>
     
    #define ll long long
     
    using namespace std;
     
    ll int a[1000010];
     
    int main()
    {
        ll int t;
        cin >> t;
     
        for(ll int i=0;i<1000010;i++)
            a[i] = i*i;
     
        while(t--)
        {
            ll int n,temp;
            cin >> n;
     
            bool flag = false;
     
            for(ll int i=0;i*i<=n;i++)
            {
                temp = n-a[i];
     
                if(binary_search(a,a+1000010,temp))
                {
                    flag = true;
                    break;
                }
            }
     
            if(flag)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    } 