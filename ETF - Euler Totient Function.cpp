#include <bits/stdc++.h>

using namespace std;

int fact[100000],f;

void primeFactors(int n)
{
	f = 0;

    if(n%2 == 0)
    {
        fact[f++] = 2;

        while (n%2 == 0)
            n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        if(n%i == 0)
        {
            fact[f++] = i;

            while (n%i == 0)
                n = n/i;
        }
    }

    if (n > 2)
        fact[f++] = n;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		if(n == 1)
		{
			cout << 1 << endl;
			continue;
		}

		primeFactors(n);

		int ans = n;

		for(int i=0;i<f;i++)
		{
			//cout << fact[i] << endl;
			ans = (ans*(fact[i]-1))/fact[i];
		}

		if(ans == n)
			cout << n-1 << endl;			
		else
			cout << ans << endl;
	}
	return 0;
}