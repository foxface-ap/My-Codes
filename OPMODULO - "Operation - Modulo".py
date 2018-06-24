import math

def solve(n):
    count = 0

    while(n > 1):
        count += 1
        n //= 2
    
    ans = 0

    for i in range(count):
        ans += (2**(i+2)-1)

    return ans

l,r = map(int,input().split())

if l > 2:
    print(solve(r)-solve(l-1))
else:
    print(solve(r))