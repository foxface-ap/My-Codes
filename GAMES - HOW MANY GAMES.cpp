#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	cin >> t;
	
	while(t--)
	{
		double n;
		cin >> n;
		
        long long int temp = 10000;
		long long int ans = n*temp;
		
		cout << temp/__gcd(ans,temp) << endl;
	}
	return 0;
}