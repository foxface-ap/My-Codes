#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int x,y;
		cin >> x >> y;

		if(x == y && x%2 == 0)
			cout << x+y << endl;
		else if(x == y)
			cout << x+y-1 << endl;
		else if(x == y+2 && y%2 == 0)
			cout << x+y << endl;
		else if(x == y+2)
			cout << x+y-1 << endl;
		else
			cout << "No Number" << endl;
	}
}