#include <bits/stdc++.h>

using namespace std;

int a[1000100][5];

int main()
{
    int n,k=0;
    cin >> n;

    while(n != 0)
    {
        k++;

        for(int i=0;i<n;i++)
        {
            a[i][0] = a[i][4] = 1000000007;

            for(int j=1;j<4;j++)
                cin >> a[i][j];
        }

        for(int j=1;j<4;j++)
            a[1][j] += a[0][2];

        for(int i=2;i<n;i++)
        {
            for(int j=1;j<4;j++)
                a[i][j] += min(a[i-1][j],min(a[i-1][j-1],a[i-1][j+1]));
        }

        cout << k << ". " << a[n-1][2] << endl;

        cin >> n;
    }
}