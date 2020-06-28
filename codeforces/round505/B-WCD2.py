from math import sqrt
n = int(input())

def getDividor(a):
    p = []
    q = []
    for i in range(2,int(sqrt(a))+1):
        if a % i == 0:
            p.append(i)
            if a//i != i:
                q.insert(0,a//i)
    return p+q+[a]
(a1,b1) = map(int,input().split())
alist = getDividor(a1)
blist = getDividor(b1)
blist = list(set(alist+blist))
print(blist)
for i in range(0,n-1):
    (ai,bi) = map(int,input().split())
    nextlist = []
    for k in blist:
        if ai % k == 0 or bi % k == 0:
            nextlist.append(k)
    #print(nextlist)
    blist = []
    for k in nextlist:
        blist.append(k)
    #print(blist)
    if len(blist) == 0:
        break
if len(blist) == 0:
    print(-1)
else:
    #print(blist)
    print(blist[0])
