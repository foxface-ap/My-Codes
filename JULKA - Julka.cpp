#include <boost/multiprecision/cpp_int.hpp>
#include <bits/stdc++.h>

namespace mp = boost::multiprecision;

#define BINT mp::cpp_int
using namespace std;

int main()
{
	int t = 10;

	while(t--)
	{
		BINT a,b;
		cin >> a >> b;

		cout << (a+b)/2 << endl;
		cout << (a-b)/2 << endl;
	}
}