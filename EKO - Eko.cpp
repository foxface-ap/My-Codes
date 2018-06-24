#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll int a[1000010];

int main()
{
    ll int n,m;
    scanf("%lld %lld",&n,&m);

    ll int low,high,count;
    low = high = 0;

    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);

        if(high < a[i])
            high = a[i];
    }

    while(low < high)
    {
        ll int mid = (low+high)/2;
        count = 0;

        for(int i=0;i<n;i++)
            count += (a[i] > mid ? a[i] - mid : 0);

        if(count > m)
        {
            low = mid+1;
            count = 0;

            for(int i=0;i<n;i++)
                count += (a[i] > low ? a[i] - low : 0);

            if(count < m)
            {
                low -= 1;
                break;
            }
        }
        else
            high = mid;
    }

    printf("%lld\n",low);

    return 0;
}