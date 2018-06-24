#include <bits/stdc++.h>

using namespace std;

char a[30010];
pair <int,int> segtree[120010];

void build(int nd, int st, int ed)
{
    if(st >= ed)
    {
        segtree[nd].first = segtree[nd].second = a[st] == '(' ? -1 : 1;
        return;
    }

    int mid = (st+ed)/2;

    build(2*nd,st,mid);
    build(2*nd+1,mid+1,ed);

    segtree[nd].first = segtree[2*nd].first + segtree[2*nd+1].first;
    segtree[nd].second = min(segtree[2*nd+1].second,segtree[2*nd+1].first+segtree[2*nd].second);
}

void update(int nd, int st, int ed, int key)
{
    if(st >= ed)
    {
        segtree[nd].first = segtree[nd].second = -segtree[nd].first;
        return;
    }

    int mid = (st+ed)/2;

    if(mid >= key)
        update(2*nd,st,mid,key);
    else
        update(2*nd+1,mid+1,ed,key);

    segtree[nd].first = segtree[2*nd].first + segtree[2*nd+1].first;
    segtree[nd].second = min(segtree[2*nd+1].second,segtree[2*nd+1].first+segtree[2*nd].second);
}

int main()
{
    for(int t=1;t<=10;t++)
    {
        int n;
        scanf("%d",&n);

        scanf("%s",a);

        build(1,0,n-1);

        int q;
        scanf("%d",&q);

        printf("Test %d:\n",t);

        while(q--)
        {
            int x;
            scanf("%d",&x);

            if(x == 0)
            {
                if(segtree[1].first == 0 && segtree[1].second == 0)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
            else
                update(1,0,n-1,x-1);
        }
    }
}