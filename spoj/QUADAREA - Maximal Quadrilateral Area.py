import math

for _ in range(int(input())):
    a,b,c,d = map(float,input().split())

    s = (a+b+c+d)/2

    print(math.sqrt((s-a)*(s-b)*(s-c)*(s-d)))
