#include <bits/stdc++.h>

using namespace std;

string s1[8] = {"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT","HHH"};

int solve(string s, int n)
{
	int count = 0;

	for(int i=0;i<s.size()-2;i++)
	{
		if(s[i] == s1[n][0] && s[i+1] == s1[n][1] && s[i+2] == s1[n][2])
			count++;
	}

	return count;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		string s;
		cin >> n >> s;

		cout << n << " ";

		for(int i=0;i<8;i++)
			cout << solve(s,i) << " ";
		cout << endl;

	}
}