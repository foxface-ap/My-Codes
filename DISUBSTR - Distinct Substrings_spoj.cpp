#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		string s;
		cin >> s;

		int ans = 0,count=1;

		for(int i=0;i<s.size();i++)
		{
			for(int j=i+1;j<s.size();j++)
			{
				if(s[i] == s[j])
				{
					ans += count;
					count = 1;
					break;
				}
				count++;
			}
		}

		ans += (count*(count+1))/2;

		cout << ans << endl;
	}
}