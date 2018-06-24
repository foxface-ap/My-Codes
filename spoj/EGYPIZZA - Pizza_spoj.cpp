#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	if(n == 0)
	{
		cout << 1 << endl;
		return 0;
	}

	map <string,int> m;

	string s;

	for(int i=0;i<n;i++)
	{
		cin >> s;

		m[s]++;
	}

	int ans = 0;

	ans += (m["1/2"]/2);
	m["1/2"] -= 2*ans;
	ans += m["3/4"];

	if(m["3/4"] >= m["1/4"])
		ans += m["1/2"];
	else
	{
		m["1/4"] -= m["3/4"];
		int temp = m["1/4"]%4;
		ans += (m["1/4"]/4);

		if(temp == 0)
			ans += m["1/2"];
		else if(temp == 3)
			ans += (m["1/2"]+1);
		else
			ans += max(1,m["1/2"]);
	}

	cout << ans+1 << endl;
}