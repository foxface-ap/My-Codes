#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
	int n;
	cin >> n;

	while(n != -1)
	{
		int temp = (1+sqrt(1+4*1.0*(n-1)/3))/2;

		temp = 3*temp*(temp-1)+1;

		if(temp == n)
			cout << "Y" << endl;
		else
			cout << "N" << endl;

		cin >> n;
	}
}