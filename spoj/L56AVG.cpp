#include <bits/stdc++.h>

using namespace std;

int a[100010];

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n,x;
		cin >> n;

		a[0] = 0;

		for(int i=1;i<=n;i++)
		{
			cin >> x;
			a[i] = a[i-1] + x;
		}

		float max = 0,temp;

		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(i != 1 && j != n)
					temp = min(1.0*a[i-1]/(i-1),min(1.0*(a[j]-a[i-1])/(j-i+1),1.0*(a[n]-a[j])/(n-j)));
				else if(i != 1 && j == n)
					temp = min(1.0*a[i-1]/(i-1),1.0*(a[j]-a[i-1])/(j-i+1));
				else if(i == 1 && j != n)
					temp = min(1.0*(a[j]-a[i-1])/(j-i+1),1.0*(a[n]-a[j])/(n-j));
				else
					temp = 1.0*a[n]/n;

				if(max < temp)
					max = temp;
			}
		}

		cout << max << endl;
	}
}