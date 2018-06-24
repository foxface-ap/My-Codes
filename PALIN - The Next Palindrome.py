for _ in range(int(input())):
    a = input()
    if a.strip('9') == '':
        print('1', end="")
        for _ in range(len(a)-1):
            print('0', end="")
        print('1')
        continue
    n = len(a)//2
    b = a[:n]
    if len(a)%2 == 0:
        b = b + b[::-1]
    else:
        b = b + a[n] + b[::-1]
    if a >= b:
        y = '123456789'
        x = ''
        c = 1
        i = (len(a)+1)//2 - 1
        while c:
            m = int(a[i])
            if m == 9:
                x = '0' + x
            else:
                x = y[m] + x
                x = a[:i] + x
                break
            i -= 1
            if i < 0:
                x = '1' + x
                break
        if len(a)%2 == 0:
            print(x + x[::-1])
        else:
            print(x + x[:-1][::-1])
    else:
        print(b)