#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n;

    while(cin >> n)
    {
        string s1,s2;
        cin >> s1 >> s2;
        
        if(n > s2.size())
        {
           cout << endl;
           continue;
        }

        vector <int> v;

        for(int i=0;i<=s2.size()-s1.size();i++)
            v.push_back(i);

        int j = 0;

        while(j < s1.size())
        {
            vector <int> temp;

            for(int i=0;i<v.size();i++)
            {
                if(s1[j] == s2[v[i]])
                    temp.push_back(v[i]+1);
            }

            v.empty();
            v = temp;

            j++;
        }

        for(int i=0;i<v.size();i++)
            cout << v[i]-n << endl;
        cout << endl;
    }
}