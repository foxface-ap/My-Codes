#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector <ll int> v;
	v.push_back(1);
	v.push_back(1);

	for(int i=2;i<20;i++)
		v.push_back(v[i-1]+v[i-2]);

	for(int i=1;i<=n;i++)
	{
		if(binary_search(v.begin(),v.end(),i))
			cout << "O";
		else
			cout << "o";
	}
	cout << endl;
}