#include <bits/stdc++.h>

using namespace std;

int a[1000][1000];

int main()
{
	int n,m;
	cin >> n >> m;

	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=m;j++)
			cin >> a[i][j];
	}

	for(int i=0;i<n;i++)
		a[i][0] = a[i][n+1] = 1000000007;

	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
			a[i][j] = a[i][j] + min(a[i-1][j-1],min(a[i-1][j],a[i-1][j+1]));
	}

	int max = 1000000007;

	for(int i=1;i<=m;i++)
	{
		if(max > a[n-1][i])
			max = a[n-1][i];
	}

	cout << max << endl;
}