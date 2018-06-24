#include <bits/stdc++.h>

using namespace std;

int a[1010][1010],b[1010][1010],n,m;

void solve(int x,int y, int k)
{
	if(k == 0 || a[x][y] == -1)
		return;
	else if((x >= 0 && x < n) && (y >= 0 && y < m))
	{
		if(b[x-1][y] < (k-1))
			solve(x-1,y,k-1);
		if(b[x+1][y] < (k-1))
			solve(x+1,y,k-1);
		if(b[x][y-1] < (k-1))
			solve(x,y-1,k-1);
		if(b[x][y+1] < (k-1))
			solve(x,y+1,k-1);
		b[x][y] = k;
	}
	return;
}

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d%d",&n,&m);

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%d",&a[i][j]);
				b[i][j] = 0;
			}
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(a[i][j] != -1 && a[i][j] != 0)
					solve(i,j,a[i][j]+1);
			}
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(a[i][j] == -1)
					printf("B");
				else if(b[i][j] == 0)
					printf("N");
				else
					printf("Y");
			}
			printf("\n");
		}
	}
}