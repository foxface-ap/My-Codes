#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n,k,s;
		cin >> n >> k >> s;

		int temp = s/7;

		int count = n*(s-temp);

		if(count < s*k)
			cout << -1 << endl;
		else
			cout << ceil(s*k*1.0/n) << endl;
	}
}