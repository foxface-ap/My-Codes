#include <bits/stdc++.h>

using namespace std;

int a[100];

int main()
{
    a[0] = 1;

    for(int i=1;i<32;i++)
        a[i] = 2*a[i-1];

    while(true)
    {
        string s;
        cin >> s;

        if(s == "00e0")
            break;

        int n = ((s[0]-'0')*10 + (s[1]-'0'))*pow(10,s[3]-'0');

        int *p = upper_bound(a,a+32,n);

        cout << 2*n - *p + 1 << endl;
    }
}