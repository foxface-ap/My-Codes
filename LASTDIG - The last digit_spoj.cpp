#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		ll int a,b;
		cin >> a >> b;

		if((a%10) == 0)
			cout << 0 << endl;
		else if(b == 0)
			cout << 1 << endl;
		else
			cout <<	(int)pow(a%10,4+b%4)%10 << endl;
	}
}