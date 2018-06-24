#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m1;
	cin >> n >> m1;

	map <string, string> m;

	string s1,s2;

	for(int i=0;i<n;i++)
	{
		cin >> s1 >> s2;

		m[s2] = s1;
	}

	for(int i=0;i<m1;i++)
	{
		cin >> s1 >> s2;

		cout << s1 << " " << s2 << " #";

		s2.pop_back();

		cout << m[s2] << endl;
	}
}