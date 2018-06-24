for _ in range(int(input())):
    n,m,d = map(int,input().split())

    count = 0

    for i in range(n):
        x = int(input())

        if x > d:
            count += 1

    if count >= m:
        print("YES")
    else:
        print("NO")
    
    input()