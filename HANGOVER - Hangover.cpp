#include <bits/stdc++.h>

using namespace std;

int main()
{
	float t;
	cin >> t;

	while(t != 0.00)
	{
		int i;
		for(i=2;;i++)
		{
			t -= (1.0/i);

			if(t <= 0)
				break;
		}

		cout << i-1 << " card(s)" << endl;
		cin >> t;
	}
}