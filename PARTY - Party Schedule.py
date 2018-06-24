w,n = map(int,input().split())

a = []
b = []

def solve(s,e,w):
    if s == e:
        return 0
    elif w < a[s]:
        return solve(s+1,e,w)
    else:
        return max(solve(s+1,e,w),a[s]+solve(s+1,e,w-a[s]))

for i in range(n):
    x,y = map(int,input().split())

    a.append(x)
    b.append(y)

print(solve(0,n,w))