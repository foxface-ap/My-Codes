def gcd(a,b):
	if b==0:
		return a
	else:
		return gcd(b,a%b)

for _ in range(int(input())):
    n,r = map(int,input().split())

    ans = gcd(r,n)

    print(ans)