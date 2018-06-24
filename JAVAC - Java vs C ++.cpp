#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;

    while(cin >> s)
    {
        int k = s.size();

        if(s[0] == '_' || s[k-1] == '_' || (s[0] >= 65 && s[0] <= 90))
        {
            printf("Error!\n");
            continue;
        }

        bool flag = false,flag1 = false;
        string s1 = "";

        for(int i=0;i<k;i++)
        {
            if(s[i] >= 65 && s[i] <= 90)
                flag1 = true;
        }

        for(int i=0;i<k;i++)
        {
            if(s[i] == '_')
            {
                if(s[i+1] == '_' || s[i-1] == '_' || flag1)
                    flag = true;
                else
                {
                    i++;
                    s1 += (s[i]-32);
                }
            }
            else if(s[i] >= 65 && s[i] <= 90)
            {
                s1 += '_';
                s1 += (s[i]+32);
            }
            else
                s1 += s[i];
        }
        
        if(flag)
            printf("Error!\n");
        else
            cout << s1 << endl;
    }
}