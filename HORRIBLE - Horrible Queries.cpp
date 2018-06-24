#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll int segtree[4000010],lazy[4000010],a[1000010];

void build(int nd, int st, int ed)
{
    if(st == ed)
    {
        segtree[nd] = a[st];
        lazy[nd] = 0;
        return;
    }

    int mid = (st+ed)/2;

    build(2*nd,st,mid);
    build(2*nd+1,mid+1,ed);

    segtree[nd] = segtree[2*nd]+segtree[2*nd+1];
    lazy[nd] = 0;
}

void update(int nd, int st, int ed, int l, int r,ll int val,ll int lz)
{
    int mid = (st+ed)/2;

    if(l > ed || r < st)
    {
        segtree[nd] += (ed-st+1)*lz;
        lazy[nd] += lz;
        return;
    }

    if(st >= l && ed <= r)
    {
        segtree[nd] += (ed-st+1)*(lz+val);
        lazy[nd] += (lz+val);
        return;
    }

    update(2*nd,st,mid,l,r,val,lz+lazy[nd]);
    update(2*nd+1,mid+1,ed,l,r,val,lz+lazy[nd]);

    segtree[nd] = segtree[2*nd]+segtree[2*nd+1];
    lazy[nd] = 0;
}

ll int quary(int nd, int st, int ed, int l, int r,ll int lz)
{
    int mid = (st+ed)/2;

    if(l > ed || r < st)
    {
        segtree[nd] += (ed-st+1)*lz;
        lazy[nd] += lz;
        return 0;
    }

    if(st >= l && ed <= r)
    {
        segtree[nd] += (ed-st+1)*lz;
        lazy[nd] += lz;
        return segtree[nd];
    }

    ll int q1,q2;

    q1 = quary(2*nd,st,mid,l,r,lz+lazy[nd]);
    q2 = quary(2*nd+1,mid+1,ed,l,r,lz+lazy[nd]);

    segtree[nd] = segtree[2*nd]+segtree[2*nd+1];
    lazy[nd] = 0;

    return q1+q2;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n,c;
        cin >> n >> c;

        for(int i=0;i<n;i++)
            a[i] = 0;

        for(int i=0;i<4*n;i++)
            segtree[i] = lazy[i] = 0;
        
        while(c--)
        {
            int type;
            cin >> type;

            if(type == 0)
            {
                int p,q;
                ll int v;
                cin >> p >> q >> v;

                update(1,0,n-1,p-1,q-1,v,lazy[0]);
            }
            else
            {
                int p,q;
                cin >> p >> q;

                cout << quary(1,0,n-1,p-1,q-1,lazy[0]) << endl;
            }
        }
    }
}