#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int temp,count = 0;

	for(int i=1;i!=0;i++)
	{
		temp = n/i;

		if(temp < i)
			break;

		count += (temp-i+1);
	}

	cout << count << endl;
}