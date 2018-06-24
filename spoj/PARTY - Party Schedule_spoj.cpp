#include <bits/stdc++.h>

using namespace std;

pair <int,int> knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   pair <int,int> K[n+1][W+1];
 
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           	if (i==0 || w==0)
               	K[i][w].first = K[i][w].second = 0;
           	else if (wt[i-1] <= w && (val[i-1] + K[i-1][w-wt[i-1]].second) > K[i-1][w].second)
           	{
           		K[i][w].second = val[i-1] + K[i-1][w-wt[i-1]].second;
           		K[i][w].first = wt[i-1] + K[i-1][w-wt[i-1]].first;
           	}
           	else
                K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][W];
}

int main()
{
	int n,m;
	cin >> n >> m;

	while(n != 0 || m != 0)
	{
		int a[505],b[505];

		for(int i=0;i<m;i++)
			cin >> a[i] >> b[i];

		pair <int,int> temp = knapSack(n,a,b,m);

		cout << temp.first << " " << temp.second << endl;

		cin >> n >> m;
	}
}