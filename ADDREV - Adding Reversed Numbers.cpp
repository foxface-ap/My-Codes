#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		string s1,s2;
		cin >> s1 >> s2;

		queue <int> p1,p2,p;

		int i=0;

		while(s1[i] != '\0')
		{
			p1.push(s1[i] - 48);
			i++;
		}

		i = 0;

		while(s2[i] != '\0')
		{
			p2.push(s2[i] - 48);
			i++;
		}

		i = 0;

		while(!p1.empty() && !p2.empty())
		{
			i += p1.front() + p2.front();

			p.push(i%10);

			i /= 10;

			p1.pop();
			p2.pop();
		}

		while(!p1.empty())
		{
			i += p1.front();

			p.push(i%10);

			i /= 10;

			p1.pop();
		}

		while(!p2.empty())
		{
			i += p2.front();

			p.push(i%10);

			i /= 10;

			p2.pop();
		}

		if(i != 0)
			p.push(i);

		while(!p.empty())
		{
			if(p.front() != 0)
				break;

			p.pop();
		}

		while(!p.empty())
		{
			cout << p.front();

			p.pop();
		}
		cout << endl;
	}
}