s = raw_input()
while s != '':
    if s[0].isupper() or s[0] == '_' or s[-1] == '_' or '__' in s:
        print("Error!")
    elif s.isalpha():
        s1 = ''
        for i in range(len(s)):
            if s[i].isupper():
                s1 += '_'
                s1 += s[i].lower()
            else:
                s1 += s[i]
        print(s1)
    else:
        if s.lower() != s:
            print("Error!")
        else:
            s1 = s[0]
            for i in range(1,len(s)):
                if s[i] == '_':
                    continue
                else:
                    if s[i-1] == '_':
                        s1 += s[i].upper()
                    else:
                        s1 += s[i]
            print(s1)
    s = raw_input()