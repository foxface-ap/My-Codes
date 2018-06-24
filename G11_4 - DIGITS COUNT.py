a = [0,0,0,0,0,0,0,0,0,0]

def solve(n):
    k = len(str(n))-1
    count = 1

    while n:
        m = n%10
        ans += (m-1)*count
        count *= 10
        n //= 10

l,r = map(int,input().split())

while l != 0 or r != 0:
    print(solve(r)-solve(l-1))

    l,r = map(int,input().split())