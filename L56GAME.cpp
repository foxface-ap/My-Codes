#include <bits/stdc++.h>

using namespace std;

int a[100010];

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		int count = 0;

		for(int i=0;i<n;i++)
		{
			cin >> a[i];

			if(a[i]%2 != 0)
				count++;
		}

		if(count%2 == 0)
			cout << 1 << endl;
		else
			cout << 2 << endl;
	}
}