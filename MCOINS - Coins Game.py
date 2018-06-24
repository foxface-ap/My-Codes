dp = {}

def solve(k,l):
    x = 1
    y = min(k,l)
    z = max(k,l)

    for i in range(0,1000010):
        if i < 1:
            dp[i] = False
        elif i < y:
            dp[i] = not dp[i-1]
        elif i < z:
            dp[i] = not (dp[i-x] and dp[i-y])
        else:
            dp[i] = not (dp[i-x] and dp[i-y] and dp[i-z])

k,l,n = map(int,input().split())

a = list(map(int,input().split()))

solve(k,l)

s = ""

for i in a:
    if dp[i]:
        s += 'A'
    else:
        s += 'B'

print(s)

