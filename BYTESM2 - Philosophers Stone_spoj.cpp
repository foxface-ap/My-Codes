#include <bits/stdc++.h>

using namespace std;

int a[100][102];

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		for(int i=0;i<100;i++)
		{
			for(int j=0;j<102;j++)
				a[i][j] = 0;
		}

		int h,w;
		cin >> h >> w;

		for(int i=0;i<h;i++)
		{
			for(int j=1;j<=w;j++)
				cin >> a[i][j];
		}

		for(int i=1;i<h;i++)
		{
			for(int j=1;j<=w;j++)
				a[i][j] += max(a[i-1][j],max(a[i-1][j-1],a[i-1][j+1]));
		}

		/*for(int i=0;i<h;i++)
		{
			for(int j=0;j<=w+1;j++)
				cout << a[i][j] << " ";
			cout << endl;
		}*/

		int max = 0;

		for(int i=1;i<=w;i++)
		{
			if(max < a[h-1][i])
				max = a[h-1][i];
		}

		cout << max << endl;
	}
}