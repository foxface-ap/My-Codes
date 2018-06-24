#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		ll int n,x;
		cin >> x >> n;

		ll int sum = n*(n+1)/2 - x;

		if(sum%2 != 0 || n < 4)
			cout << "impossible" << endl;
		else
		{
			ll int temp = 0, k = n;

			while(temp < sum)
			{
				if(k == x)
				{
					k--;
					continue;
				}
				sum -= k;
				temp += k;
				k--;
			}

			if(temp == sum)
			{
				for(int i=1;i<=k;i++)
				{
					if(i == x)
						cout << 2;
					else
						cout << 0;
				}

				for(int i=k+1;i<=n;i++)
				{
					if(i == x)
						cout << 2;
					else
						cout << 1;
				}
			}
			else
			{
				k++;
				sum += k;
				temp -= k;

				temp = sum - temp;
				temp /= 2;

				if(temp == x)
				{
					if(temp < 3)
					{
						temp = 0;
						k = n-1;
						sum = n*(n+1)/2 - x;

						while(temp < sum)
						{
							if(k == x)
							{
								k--;
								continue;
							}
							sum -= k;
							temp += k;
							k--;
						}

						if(temp == sum)
						{
							for(int i=1;i<=k;i++)
							{
								if(i == x)
									cout << 2;
								else
									cout << 0;
							}

							for(int i=k+1;i<n;i++)
							{
								if(i == x)
									cout << 2;
								else
									cout << 1;
							}
							cout << 0 << endl;
						}
						else
						{
							k++;
							sum += k;
							temp -= k;

							temp = sum - temp;
							temp /= 2;

							for(int i=1;i<=k;i++)
							{
								if(i == x)
									cout << 2;
								else if(i == temp)
									cout << 1;
								else
									cout << 0;
							}

							for(int i=k+1;i<n;i++)
							{
								if(i == x)
									cout << 2;
								else
									cout << 1;
							}

							cout << 0 << endl;
						}
					}
					else
					{
						cout << 1;

						for(int i=2;i<=k;i++)
						{
							if(i == x)
								cout << 2;
							else if(i == temp-1)
								cout << 1;
							else
								cout << 0;
						}

						for(int i=k+1;i<=n;i++)
						{
							if(i == x)
								cout << 2;
							else
								cout << 1;
						}
					}

					cout << endl;
					continue;
				}

				for(int i=1;i<=k;i++)
				{
					if(i == x)
						cout << 2;
					else if(i == temp)
						cout << 1;
					else
						cout << 0;
				}

				for(int i=k+1;i<=n;i++)
				{
					if(i == x)
						cout << 2;
					else
						cout << 1;
				}

			}
			cout << endl;
		}
	}
}
