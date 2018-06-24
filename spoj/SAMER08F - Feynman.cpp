#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	while(n != 0)
	{
		long long int count = 0;

		while(n > 0)
		{
			count += n*n;
			n--;
		}

		cout << count << endl;

		cin >> n;
	}
}