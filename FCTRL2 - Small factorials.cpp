#include <boost/multiprecision/cpp_int.hpp>
#include <bits/stdc++.h>

namespace mp = boost::multiprecision;

#define BINT mp::cpp_int
using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		BINT ans = 1;

		for(int i=1;i<=n;i++)
			ans *= i;

		cout << ans << endl;
	}
}