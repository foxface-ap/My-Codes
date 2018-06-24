a,b,c = map(str,input().split())

min = 10000

d = []

e = [a,b,c]

for i in e:
    d.append(int(i))
    for j in e:
        d.append(int(i+j))
        for k in e:
            d.append(int(i+j+k))
            for l in e:
                d.append(int(i+j+k+l))
                for m in e:
                    d.append(int(i+j+k+l+m))
                    for n in e:
                        d.append(int(i+j+k+l+m+n))
                        for o in e:
                            d.append(int(i+j+k+l+m+n+o))
                            for p in e:
                                d.append(int(i+j+k+l+m+n+o+p))
                                for q in e:
                                    d.append(int(i+j+k+l+m+n+o+p+q))

for i in d:
    if i%3 == 0:
        if min > i:
            min = i

print(min)