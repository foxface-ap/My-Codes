#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k = 0;
    string s;
    cin >> s;

    while(s[0] != '-')
    {
        stack <char> s1;

        int count = 0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '{')
            {
                s1.push('{');
            }
            else
            {
                if(s1.empty())
                {
                    count++;
                    s1.push('{');
                }
                else
                    s1.pop();
            }
        }

        count += s1.size()/2;

        cout << ++k << ". " << count << endl;

        cin >> s;
    }
}