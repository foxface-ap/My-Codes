#include <bits/stdc++.h>

using namespace std;

char s1[5005],s2[5005];
int e1,e2;

int solver(int st1, int st2)
{
	cout << "ab" << endl;
	cout << st1 << st2 << e1 << e2 << endl;
	if(st1 == e1 && st2 == e2)
	{
		cout << "an" << endl;
		return 0;
	}
	else if(st1 != e1 && st2 == e2)
	{
		cout << "ad" << endl;
		int count=1;
		char temp = s1[st1];

		for(int i=st1;i<e1;i++)
		{
			if(s1[i] != temp)
			{
				count++;
				temp = s1[i];
			}
		}

		return count;
	}
	else if(st1 == e1 && st2 != e2)
	{
		cout << "ar" << endl;
		int count=1;
		char temp = s2[st2];

		for(int i=st2;i<e2;i++)
		{
			if(s2[i] != temp)
			{
				count++;
				temp = s2[i];
			}
		}

		return count;
	}
	else if(s1[st1] != s2[st2])
	{
		cout << "ac" << endl;
		int i;

		for(i=st1;i<e1;i++)
		{
			if(s1[i] == s2[st2])
				break;
		}

		if(i == e1)
			return 1+solver(st1,st2+1);
		else
			return min(solver(st1,st2+1)+1,solver(i+1,st2+1));
	}
	else
	{
		cout << "as" << endl;
		return solver(st1+1,st2+1);
	}
}

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d %d",&e1,&e2);

		scanf("%s %s",&s1,&s2);

		printf("%d\n",solver(0,0));
	}

	return 0;
}