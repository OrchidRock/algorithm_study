Limit = 10000
T = int(input())
for i in range(T):
    n = int(input())
    A = [int(key) for key in input().split()]
    s = [0 for i in range(0,Limit+1)]
    p=0
    q=0
    for j in range(0,n):
        t = A[j]
        s[t] += 1
        if s[t] >= 4:
            p = t
            q = t
            break
        elif s[t] > 1:
            if p == 0:
                p = t
            elif q == 0:
                q = t
            else:
                if (1-min(q,t)/max(q,t)) < (1-min(p,q)/max(p,q)):
                    p = q
                    q = t
    print(str(p) + " " + str(p) + " " + str(q) + " " + str(q))
    
