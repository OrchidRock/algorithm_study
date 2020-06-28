q = int(input())

for i in range(0,q):
    (n,m,k) = map(int,input().split())
    p = min(n,m)
    q = max(n,m) - p
    if k < p + q:
        print(-1)
    elif k == p + q:
        print(p)
    elif q == 0:
        if (k-p) % 2 == 0:
            print(k)
        else:
            print(k-2)
    else:
        print(k-q)


