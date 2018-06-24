#include <bits/stdc++.h>
	
#define ll long long
	
using namespace std;
	
map <ll int,ll int> m;
	
ll int solve(ll int n)
{
	if(n < 12)
		return n;
	else
	{
		if(m[n/2] == 0)
			m[n/2] = solve(n/2);
	
		if(m[n/3] == 0)
			m[n/3] = solve(n/3);
	
		if(m[n/4] == 0)
			m[n/4] = solve(n/4);
	
		return m[n/2]+m[n/3]+m[n/4];
	}
}
	
int main()
{
	ll int n;
	
	while(scanf("%lld",&n) != EOF)
		cout << solve(n) << endl;
} 