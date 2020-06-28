(n,h) = map(int,input().split())
ans = h
sd = [0 for i in range(0,n)]
sa = [0 for i in range(0,n)]
lastx = 0
lasty = 0
p = q = 0
for i in range(0,n):
    (x,y) = map(int,input().split())
    if i == 1:
        p = x
        sa[i] += (y -x)
        sd[i] += 0
    else:
        sd[i] += sd[i-1] + (x-lasty)
        sa[i] += sa[i-1] + (y-x)
    lasty = y
    lastx = x
    if sd[i] >= h:

