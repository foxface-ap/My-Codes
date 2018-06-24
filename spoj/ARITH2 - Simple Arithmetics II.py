t = int(input())

while t > 0 :
    c = input()
    
    a = list(input().split())

    b = int(a[0])

    for i in range(1,len(a),2):
        if a[i] == '+' :
            b = b + int(a[i+1])
        elif a[i] == '-' :
            b = b - int(a[i+1])
        elif a[i] == '*' :
            b = b * int(a[i+1])
        elif a[i] == '/' :
            b = int(b / int(a[i+1]))
        else :
            break

    print(b)

    t = t - 1