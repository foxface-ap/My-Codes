#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        string s[100010];
        char s1[1000];
        map <string,int> m;

        int n,k=0;
        cin >> n;

        while(n--)
        {
            getchar();

            scanf("%[^\n]s",s1);

            if(m[s1] == 0)
                s[k++] = s1;

            m[s1]++;
        }

        sort(s,s+k);

        for(int i=0;i<k;i++)
            cout << s[i] << " " << m[s[i]] << endl;
        cout << endl;

        //getchar();
    }
}