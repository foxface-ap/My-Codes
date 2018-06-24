#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;

	for(int j=1;j<=t;j++)
	{
		string s;
		unsigned long long int n;

		cin >> s >> n;

		if((s[s.size()-1] - '0') == 0)
			cout << 0 << endl;
		else if(n == 0)
			cout << 1 << endl;
		else
			cout << (int)pow((s[s.size()-1] -'0'),n%4+4)%10 << endl;
	}
}