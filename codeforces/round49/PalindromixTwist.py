T =int(input())
for i in range(T):
    n = int(input())
    s = input()
    r = True
    l = len(s)
    for j in range(0,l//2):
        x = s[j]
        y = s[l-j-1]
        nextx = []
        nexty = []
        if x == 'a':
            nextx.append(ord(x) + 1)
        elif x == 'z':
            nextx.append(ord(x) - 1)
        else:
            nextx.append(ord(x) + 1)
            nextx.append(ord(x) - 1)
        if y == 'a':
            nexty.append(ord(y) + 1)
        elif y == 'z':
            nexty.append(ord(y) - 1)
        else:
            nexty.append(ord(y) + 1)
            nexty.append(ord(y) - 1)
        f = False
        for p in nextx:
            for q in nexty:
                if p == q:
                    f = True
                    break
            if f:
                break
        if f == False:
            r = False
            break
    if r:
        print("YES")
    else:
        print("NO")

