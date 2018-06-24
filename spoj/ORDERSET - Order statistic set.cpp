#include <bits/stdc++.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long int
#define ull unsigned long long int

int main()
{
    /*fastIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/

    set <int> s;

    int q;
    cin >> q;

    while(q--)
    {
        char t;
        int x;
        cin >> t;
        cin >> x;

        if(t == 'I')
            s.insert(x);
        else if(t == 'D')
            s.erase(x);
        else if(t == 'K')
        {
            if(s.find(x) == s.end())
                cout << "invalid" << endl;
            else
                cout << *s.find(x) << endl;
        }
        else
            cout << *s.lower_bound(x) << endl;
    }
}