#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll int a[1000010],b[1000010],co = 0;

void merge(ll int start,ll int mid,ll int end)
{
	ll int i,j,k;
	i = start;
	j = mid+1;
	k = 0;

	while(i <= mid && j <= end)
	{
		if(a[i] > a[j])
		{
			co += (mid-i+1);
			b[k++] = a[j++];
		}
		else
			b[k++] = a[i++];
	}

	while(i <= mid)
		b[k++] = a[i++];

	while(j <= end)
		b[k++] = a[j++];

	for(ll int i=start,k=0;i<=end;i++,k++)
		a[i] = b[k];
}

void mergesort(ll int start,ll int end)
{
	if(start >= end)
		return;

	ll int mid = (start+end)/2;

	mergesort(start,mid);
	mergesort(mid+1,end);

	merge(start,mid,end);
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		ll int n;
		cin >> n;

		for(ll int i=0;i<n;i++)
			cin >> a[i];

		co = 0;

		mergesort(0,n-1);

		cout << co << endl;
	}
}