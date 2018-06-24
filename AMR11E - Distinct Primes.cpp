#include <bits/stdc++.h>

using namespace std;

vector <int> v;
int p[1000010];

int main()
{
    memset(p,0,1000010*sizeof(p[0]));

    for(int i=2;i*i<1000010;i++)
    {
        if(p[i] == 0)
        {
            for(int j=2*i;j<1000010;j+=i)
                p[j]++;
        }
    }

    for(int i=2;i<1000010;i++)
    {
        if(p[i] > 2)
            v.push_back(i);
    }

    //cout << p[1902] << endl;

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        cout << v[n-1] << endl;
    }
}