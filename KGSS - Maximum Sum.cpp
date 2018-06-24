#include <bits/stdc++.h>

#define pb push_back

using namespace std;

struct kgss{
    int max1,max2;
};

kgss tree[4000010];
int a[1000010];

void build(int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node].max1 = a[start];
        tree[node].max2 = -1;
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children

        kgss p1,p2;
        p1 = tree[2*node];
        p2 = tree[2*node+1];

        vector <int> v;

        v.pb(p1.max1);
        v.pb(p1.max2);
        v.pb(p2.max1);
        v.pb(p2.max2);
        sort(v.begin(),v.end());

        tree[node].max1 = v[3];
        tree[node].max2 = v[2];
    }
}

void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        // Leaf node
        a[idx] = val;
        tree[node].max1 = a[idx];
        tree[node].max2 = -1;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        kgss p1,p2;
        p1 = tree[2*node];
        p2 = tree[2*node+1];

        vector <int> v;

        v.pb(p1.max1);
        v.pb(p1.max2);
        v.pb(p2.max1);
        v.pb(p2.max2);
        sort(v.begin(),v.end());

        tree[node].max1 = v[3];
        tree[node].max2 = v[2];
    }
}

kgss query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return (kgss) {-1,-1};
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    kgss p1 = query(2*node, start, mid, l, r);
    kgss p2 = query(2*node+1, mid+1, end, l, r);

    vector <int> v;

    v.pb(p1.max1);
    v.pb(p1.max2);
    v.pb(p2.max1);
    v.pb(p2.max2);
    sort(v.begin(),v.end());

    return (kgss) {v[3],v[2]};
}

int main()
{
    int n,q;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    build(1,0,n-1);

    scanf("%d",&q);

    while(q--)
    {
        char x;
        cin >> x;

        if (x == 'U')
        {
            int y,z;
            scanf("%d %d",&y,&z);

            update(1,0,n-1,y-1,z);
        }
        else
        {
            int y,z;
            scanf("%d %d",&y,&z);

            kgss ans = query(1,0,n-1,y-1,z-1);

            printf("%d\n",ans.max1 + ans.max2);
        }
    }
}