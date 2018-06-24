fact = [1,1]

for i in range(2,1000010):
	fact.append(fact[i-1]*i)

for _ in range(int(input())):
    n,r = map(int,input().split())

    print(fact[n-1]//(fact[r-1]*fact[n-r]))