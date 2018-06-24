#include <bits/stdc++.h>

using namespace std;

int solve(string s)
{
	int t = 0, k = s.size(),i = 0;

	while(i<k)
	{
		t += (s[k-i-1] - '0')*pow(10,i);
		i++;
	}

	return t;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		string a,b,c;
		string aa,bb;

		int temp1,temp2;

		cin >> a >> aa >> b >> bb >> c;

		if(aa == "+" && bb == "=")
		{
			if(a.find("machula") != string::npos)
			{
				temp1 = solve(b);
				temp2 = solve(c);

				temp2 -= temp1;

				cout << temp2 << " + " << b << " = " << c << endl;
			}
			else if(b.find("machula") != string::npos)
			{
				temp1 = solve(a);
				temp2 = solve(c);

				temp2 -= temp1;

				cout << a << " + " << temp2 << " = " << c << endl;
			}
			else
			{
				temp1 = solve(a);
				temp2 = solve(b);

				temp2 += temp1;

				cout << a << " + " << b << " = " << temp2 << endl;
			}
		}
	}
}