#include <bits/stdc++.h>

using namespace std;

const float pi = 3.14159;

int main()
{
	int l;
	cin >> l;

	while(l != 0)
	{
		printf("%.2f\n",1.0*l*l/2/pi);
		cin >> l;
	}
}