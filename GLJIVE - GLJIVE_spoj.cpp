#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a[10];

	for(int i=0;i<10;i++)
		cin >> a[i];

	int sum=0,ans;

	for(int i=0;i<10;i++)
	{
		sum += a[i];

		if(sum < 100)
			ans = sum;
		else if(sum == 100)
		{
			ans = sum;
			break;
		}
		else
		{
			if((100-ans) >= (sum-100))
				ans = sum;

			break;
		}
	}

	cout << ans << endl;

}