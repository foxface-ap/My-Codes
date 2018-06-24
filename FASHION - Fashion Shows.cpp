#include <bits/stdc++.h>

using namespace std;

int a[100010],b[100010];

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		for(int i=0;i<n;i++)
			cin >> a[i];

		for(int i=0;i<n;i++)
			cin >> b[i];

		sort(a,a+n);
		sort(b,b+n);

		int ans = 0;

		for(int i=0;i<n;i++)
			ans += a[i]*b[i];

		cout << ans << endl;
	}
}