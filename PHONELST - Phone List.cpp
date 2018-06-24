#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        string s[10010];
        map <string,int> m;

        bool flag = false;

        for(int i=0;i<n;i++)
        {
            cin >> s[i];
            
            if(m[s[i]] != 0)
                flag = true;

            m[s[i]]++;
        }

        for(int i=0;i<n;i++)
        {
            int j = s[i].size();

            for(int k=1;k<j;k++)
            {
                string s1 = s[i].substr(0,k);

                if(m[s1] != 0)
                {
                    flag = true;
                    break;
                }
            }
        }

        if(flag)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}