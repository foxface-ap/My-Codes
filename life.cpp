#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;

	vector <int> v;

	for(int i=0;i != -1;i++)
	{
		cin >> n;

		if(n == 42)
			break;

		v.push_back(n);
	}

	for(int i=0;i<v.size();i++)
		cout << v[i] << endl;
}