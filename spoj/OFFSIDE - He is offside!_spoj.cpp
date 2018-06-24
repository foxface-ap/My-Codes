#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a,b;
	cin >> a >> b;

	while(a != 0 && b != 0)
	{
		int c[100010],d[100010];

		for(int i=0;i<a;i++)
			cin >> c[i];

		for(int i=0;i<b;i++)
			cin >> d[i];

		sort(c,c+a);
		sort(d,d+b);

		if((c[0] == d[0] && c[0] == d[1]) || (c[0] >= d[1]))
			cout << "N" << endl;
		else
			cout << "Y" << endl;

		cin >> a >> b;
	}
}