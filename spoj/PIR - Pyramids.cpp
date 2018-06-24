#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        long double u,v,w,U,V,W;
        cin >> u >> v >> w >> W >> U >> V;

        long double x,y,z,X,Y,Z;

        X = (w-U+v)*(U+w+v);
        x = (U-v+w)*(U+v-w);
        Y = (w-V+u)*(w+V+u);
        y = (V-w+u)*(V+w-u);
        Z = (v-W+u)*(v+W+u);
        z = (W-v+u)*(W+v-u);

        long double a,b,c,d;

        a = sqrt(x*Y*Z);
        b = sqrt(y*Z*X);
        c = sqrt(z*X*Y);
        d = sqrt(x*y*z);

        long double p,q,r,s;

        p = -a + b + c + d;
        q = a - b + c + d;
        r = a + b - c + d;
        s = a + b + c - d;

        long double key,value;

        key = sqrt(p*q*r*s);
        value = 192*u*v*w;

        key /= value;

        printf("%.4Lf\n",key);
    }
}