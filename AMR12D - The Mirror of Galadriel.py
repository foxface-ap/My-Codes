for _ in range(int(input())):
    s = input()
    r = s[::-1]

    if s in r:
        print("YES")
    else:
        print("NO")