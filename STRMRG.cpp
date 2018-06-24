#include <bits/stdc++.h>

using namespace std;

string merge(string s1, string s2)
{
	stack <char> s;

	s.push(s1[0]);

	int i = 1, j = 0;

	while(i < s1.size() && j < s2.size())
	{
		if(s1[i] == s.top())
			s.push(s1[i++]);
		else if(s)
	}
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n,m;
		cin >> n >> m;

		string s1,s2;
		cin >> s1 >> s2;

		string s3,s4;

		s3 = merge(s1,s2);
		s4 = merge(s2,s1);
	}
}
