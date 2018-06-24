#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		int count = 0;
		int i = 5;

		while(n/i != 0)
		{
			count += (n/i);
			n /= i;
		}

		cout << count << endl;
	}
}