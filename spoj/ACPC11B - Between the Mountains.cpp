#include <bits/stdc++.h>

using namespace std;

int a[100000],b[100000];

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n,x;
        cin >> n;

        for(int i=0;i<n;i++)
            cin >> a[i];

        a[n] = 1000000007;

        sort(a,a+n);

        int m;
        cin >> m;

        int ans = 1000000007;
        bool flag = false;

        for(int i=0;i<m;i++)
        {
            cin >> x;

            if(binary_search(a,a+n,x))
            {
                ans = 0;
                flag = true;
            }
            else
            {
                int *p = upper_bound(a,a+n,x);

                int temp = abs(*p-x);
                if(temp < ans)
                    ans = temp;

                temp = abs(*(p-1)-x);
                if(temp < ans)
                    ans = temp;
            }
        }    

        if(flag)
            cout << 0 << endl;
        else
            cout << ans << endl;  
    }
}