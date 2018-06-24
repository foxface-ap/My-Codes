#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a,b,c;
	cin >> a >> b >> c;

	while(!(a == 0 && b == 0 && c == 0))
	{
		if((b-a) == (c-b))
			cout << "AP " << c+b-a << endl;
		else
			cout << "GP " << b*c/a << endl;

		cin >> a >> b >> c;
	}
}