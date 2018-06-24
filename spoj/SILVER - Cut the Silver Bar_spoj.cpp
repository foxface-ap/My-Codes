#include <bits/stdc++.h>

using namespace std;

int solve(int t)
{
	if(t == 0 || t == 1)
		return 0;
	
	return solve(t/2)+1;
}

int main()
{
	int t;
	cin >> t;

	while(t != 0)
	{
		cout << solve(t) << endl;

		cin >> t;
	}
}
