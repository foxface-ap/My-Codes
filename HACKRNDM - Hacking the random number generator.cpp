#include<bits/stdc++.h>

#define ll long long

using namespace std;

ll int a[100010];

int main()
{
    ll int n,k;
    cin >> n >> k;

    for(ll int i=0;i<n;i++)
        cin >> a[i];

    sort(a,a+n);

    ll int count = 0;

    for(ll int i=0;i<n;i++)
    {
        if(binary_search(a+i+1,a+n,a[i]+k))
            count++;
    }

    cout << count << endl;
}