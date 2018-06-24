#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		int temp = (sqrt(1+8*n)-1)/2;

		int temp1 = temp;

		temp = n - temp*(temp+1)/2;

		cout << "TERM " << n << " IS ";

		if(temp == 0)
		{
			if(temp1%2 == 0)
				cout << temp1 << "/" << 1 << endl;
			else
				cout << 1 << "/" << temp1 << endl;
		}
		else
		{
			if(temp1%2 != 0)
				cout << temp << "/" << temp1+2-temp << endl;
			else
				cout << temp1+2-temp << "/" << temp << endl;
		}
	}
}