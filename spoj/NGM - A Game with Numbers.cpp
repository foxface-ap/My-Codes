#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll int n;
    cin >> n;

    if(n%10 == 0)
        cout << 2 << endl;
    else
        cout << 1 << endl << n%10 << endl;
}