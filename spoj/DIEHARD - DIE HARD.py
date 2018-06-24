dp = {}

def solve(stage,h,a):
    t = (stage,h,a)

    if t not in dp:
        if(h <= 0 or a <= 0):
            dp[t] = 0
        elif stage == 1:
            dp[t] = max(solve(2,h-5,a-10),solve(3,h-20,a+5))+1
        elif stage == 2:
            dp[t] = max(solve(1,h+3,a+2),solve(3,h-20,a+5))+1
        else:
            dp[t] = max(solve(2,h-5,a-10),solve(1,h+3,a+2))+1
    
    return dp[t]

for _ in range(int(input())):
    h,a = map(int,input().split())

    print(max(solve(1,h+3,a+2),solve(2,h-5,a-10),solve(3,h-20,a+5)))