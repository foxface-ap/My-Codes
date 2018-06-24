#include <bits/stdc++.h>

using namespace std;

int main()
{
    while(true)
    {
        string s,ans;
        cin >> s;

        if(s == "")
            return 0;

        map <char,int> m;

        for(int i=0;i<s.size();i++)
            m[s[i]]++;

        cin >> s;
        ans = "";

        for(int i=0;i<s.size();i++)
        {
            if(m[s[i]] != 0)
            {
                ans += s[i];
                m[s[i]]--;
            }
        }

        sort(ans.begin(),ans.end());

        cout << ans << endl;
    }
}