#include <bits/stdc++.h>

using namespace std;

bool a[1000010];
vector <int> v;

void seive()
{
	for(int i=2;i<1000000;i++)
	{
		if(a[i])
		{
			for(int j=2*i;j<1000000;j+=i)
				a[j] = false;

			v.push_back(i);
		}
	}
}

int main()
{
	memset(a,true,1000010*sizeof(a[0]));
	seive();

	int t;
	cin >> t;

	while(t--)
	{
		int n,type;
		cin >> n >> type;

		if(n == 1)
		{
			if(type == 0)
				cout << "Airborne wins." << endl;
			else
				cout << "Pagfloyd wins." << endl;
		}
		else
		{
			n = sqrt(n);
			n = upper_bound (v.begin(), v.end(), n) - v.begin();
			n++;

			if(type == 0)
			{
				if(n%2 != 0)
					cout << "Airborne wins." << endl;
				else
					cout << "Pagfloyd wins." << endl;
			}
			else
			{
				if(n%2 == 0)
					cout << "Airborne wins." << endl;
				else
					cout << "Pagfloyd wins." << endl;
			}
		}
	}
}