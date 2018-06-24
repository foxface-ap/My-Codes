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

		int k = sqrt(n);

		int count = k;

		for(int i=2;i<=k;i++)
		{
			for(int j=k+1;j*i<=n;j++)
			{
				if(j > k)
					count++;
			}
		}

		cout << n-count << endl;
	}
}