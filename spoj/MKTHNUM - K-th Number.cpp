    #include <bits/stdc++.h>
     
    using namespace std;
     
    set <int> segtree[4000010];
    int a[1000010];
     
    set <int> merge(set <int> x, set <int> y)
    {
        if(x.size() > y.size())
        {
            set <int> :: iterator it;
     
            for(it = y.begin();it != y.end();it++)
                x.insert(*it);
     
            return x;
        }
        else
        {
            set <int> :: iterator it;
     
            for(it = x.begin();it != x.end();it++)
                y.insert(*it);
     
            return y;
        }
    }
     
    void build(int nd, int st, int ed)
    {
        if(st == ed)
        {
            segtree[nd].insert(a[st]);
            return;
        }
     
        int mid = (st+ed)/2;
     
        build(2*nd,st,mid);
        build(2*nd+1,mid+1,ed);
     
        segtree[nd] = merge(segtree[2*nd],segtree[2*nd+1]);
    }
     
    set <int> quary(int nd, int st, int ed, int l, int r)
    {
        int mid = (st+ed)/2;
     
        if(st >= l && ed <= r)
            return segtree[nd];
        else if(l > mid)
            return quary(2*nd+1,mid+1,ed,l,r);
        else if(r <= mid)
            return quary(2*nd,st,mid,l,r);
        else
            return merge(quary(2*nd,st,mid,l,r),quary(2*nd+1,mid+1,ed,l,r));
    }
     
    int main()
    {
        int n,q;
        cin >> n >> q;
     
        for(int i=0;i<n;i++)
            cin >> a[i];
     
        build(1,0,n-1);

        while(q--)
        {
            int x,y,z;
            cin >> x >> y;

            set <int> s = quary(1,0,n-1,x-1,y-1);

            cout << *s.find(s.begin()+z) << endl;
            
        }
    } 