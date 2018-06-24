#include <bits/stdc++.h>

using namespace std;

char c[201][201];

int main()
{
	int n;
	cin >> n;

	while(n != 0)
	{
		string s,s1;
		cin >> s;

		int r = s.size()/n;
		int k = 0;

		for(int i=0;i<r;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i%2 == 0)
					c[i][j] = s[k++];
				else
					c[i][n-j-1] = s[k++];
			}
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<r;j++)
			{
				s1.push_back(c[j][i]);
			}
		}

		cout << s1 << endl;

		cin >> n;
	}
}