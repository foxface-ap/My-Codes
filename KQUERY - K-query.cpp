#include <bits/stdc++.h>

#define pb push_back
    
using namespace std;
    
vector <int> segtree[120040];
int a[30010];
    
void build(int nd, int st, int ed)
{
    if(st == ed)
    {
        segtree[nd].pb(a[st]);
        return;
    }
    
    int mid = (st+ed)/2;
    
    build(2*nd,st,mid);
    build(2*nd+1,mid+1,ed);

    /*int i = 0, j = 0;

    while(i < segtree[2*nd].size() && j < segtree[2*nd+1].size())
    {
        if(segtree[2*nd][i] < segtree[2*nd+1][j])
            segtree[nd].pb(segtree[2*nd][i++]);
        else
            segtree[nd].pb(segtree[2*nd+1][j++]);
    }

    while(i < segtree[2*nd].size())
        segtree[nd].pb(segtree[2*nd][i++]);

    while(j < segtree[2*nd+1].size())
        segtree[nd].pb(segtree[2*nd+1][j++]);*/

    merge(segtree[2*nd].begin(), segtree[2*nd].end(),
          segtree[2*nd+1].begin(), segtree[2*nd+1].end(),
          back_inserter(segtree[nd]));
}
    
int quary(int nd, int st, int ed, int l, int r, int key)
{
    int mid = (st+ed)/2;
    
    if(st >= l && ed <= r)
    {
        //if(binary_search(segtree[nd].begin(),segtree[nd].end(),key))
        //    return lower_bound(segtree[nd].begin(),segtree[nd].end(),key) - segtree[nd].begin();
        //else
            
        return ed-st+1-(upper_bound(segtree[nd].begin(),segtree[nd].end(),key) - segtree[nd].begin());
    }
    else if(l > mid)
        return quary(2*nd+1,mid+1,ed,l,r,key);
    else if(r <= mid)
        return quary(2*nd,st,mid,l,r,key);
    else
        return quary(2*nd,st,mid,l,r,key) + quary(2*nd+1,mid+1,ed,l,r,key);
}
    
int main()
{
    int n;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    build(1,0,n-1);

    /*for(int i=0;i<segtree[1].size();i++)
        cout << segtree[1][i] << " ";
    cout << endl;*/
    
    int q;
    scanf("%d",&q);
    
    while(q--)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);

        printf("%d\n",quary(1,0,n-1,x-1,y-1,z));
    }
} 