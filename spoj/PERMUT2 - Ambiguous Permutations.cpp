#include <bits/stdc++.h>

using namespace std;

int a[1000010],b[1000010];

int main()
{
	int n;
	cin >> n;

	while(n != 0)
	{
		bool flag = false;

		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			b[a[i]] = i; 
		}

		for(int i=1;i<=n;i++)
		{
			if(a[i] != b[i])
				flag = true;
		}

		if(flag)
			cout << "not ambiguous" << endl;
		else
			cout << "ambiguous" << endl;

		cin >> n;
	}
}