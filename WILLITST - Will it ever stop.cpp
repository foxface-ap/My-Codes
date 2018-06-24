#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int n;
	cin >> n;

	bool flag = false;

	while(n > 1)
	{
		if(n%2 == 0)
			n /= 2;
		else
		{
			flag = true;
			break;
		}
	}

	if(flag)
		cout << "NIE" << endl;
	else
		cout << "TAK" << endl;
}