#include <bits/stdc++.h>

using namespace std;

long long int co = 0;

bool solve(int n)
{
	if(n==1)
		return true;

	co++;

	int temp,ans=0;

	while(n > 0)
	{
		temp = n%10;
		ans += temp*temp;
		n /= 10;
	}

	if(ans == 4)
		return false;

	solve(ans);
}

int main()
{
	int t;
	cin >> t;

	if(solve(t))
		cout << co << endl;
	else
		cout << -1 << endl;
}