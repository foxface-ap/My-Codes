#include <bits/stdc++.h>

using namespace std;

unsigned long long int a[1000010];

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n,r;
        cin >> n >> r;

        unsigned long long int ans = 1;

        if((r-1) > (n-r))
        {
            for(int i=r;i<n;i++)
                a[i] = i;

            unsigned long long int j = 2,key,temp;

            while(j <= (n-r))
            {
                key = j;

                for(int i=r;i<n;i++)
                {
                    temp = __gcd(a[i],key);
                    a[i] /= temp;
                    key /= temp;

                    if(key == 1)
                        break;
                }

                j++;
            }

            for(int i=r;i<n;i++)
                ans *= a[i];
        }
        else
        {
            for(int i=n-r+1;i<n;i++)
                a[i] = i;

            unsigned long long int j = 2,temp,key;

            while(j < r)
            {
                key = j;

                for(int i=n-r+1;i<n;i++)
                {
                    temp = __gcd(a[i],key);
                    a[i] /= temp;
                    key /= temp;

                    if(key == 1)
                        break;
                }

                j++;
            }

            for(int i=n-r+1;i<n;i++)
                ans *= a[i];
        }

        cout << ans << endl;
    }
}