#include <bits/stdc++.h>

using namespace std;

int a[100010],tree[400010],tree2[400010];

void build(int node, int start, int end)
{
    if(start == end)
    {
        tree[node] = a[start];
        tree2[node] = a[start];
    }
    else
    {
        int mid = (start + end) / 2;

        build(2*node, start, mid);
        build(2*node+1, mid+1, end);

        tree[node] = min(tree[2*node],tree[2*node+1]);
        tree2[node] = tree2[2*node]^tree2[2*node+1];
    }
}

int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
        return 1000000007;

    if(l <= start and end <= r)
        return tree[node];

    int mid = (start + end) / 2;

    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);

    return min(p1,p2);
}

int query2(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
        return 0;

    if(l <= start and end <= r)
        return tree2[node];

    int mid = (start + end) / 2;

    int p1 = query2(2*node, start, mid, l, r);
    int p2 = query2(2*node+1, mid+1, end, l, r);

    return p1^p2;
}

int main()
{
		int n,k;
		scanf("%d%d",&n,&k);

		for(int i=0;i<n;i++)
			cin >> a[i];

		vector <int> v;

		build(1,0,n-1);

		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
				v.push_back(query(1,0,n-1,i,j)*query2(1,0,n-1,i,j));
		}

		sort(v.begin(),v.end());

		cout << v[k-1] << endl;
}