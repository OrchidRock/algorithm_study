a = [[0,0],[1,4],[3,5],[0,6],[5,7],[3,9],[5,9],
     [6,10],[8,11],[8,12],[2,14],[12,16]]

def recursiveActivitySelector(a,k,n):
    m = k + 1
    while m <=n and a[m][0] <= a[k][1]:
        m += 1
    if m <= n:
        return [m] + recursiveActivitySelector(a,m,n)
    else:
        return []
def greedyActivitySelector(a,n):
    A = [1]
    k = 1
    for m in range(2,n+1):
        if a[m][0] >= a[k][1]:
            A = A + [m]
            k = m
    return A
def dpActivitySelector(a,n):
    A = []
    c = [[0 for j in range(0,n+1)] for i in range(0,n+1)]
    s = [[0 for j in range(0,n+1)] for i in range(0,n+1)]
    for i in range(1,n+1):
        for j in range(2,n+1):
            if i>=j:
                c[i][j] = 0
            else:
                for k in range(i+1,j):
                    if c[i][j] < c[i][k] + c[k][j] + 1:
                        c[i][j] = c[i][k] + c[k][j] + 1
                        s[i][j] = k
    return (c,s)
print(recursiveActivitySelector(a,0,len(a)-1))
print(greedyActivitySelector(a,len(a)-1))
(c,s) = dpActivitySelector(a,len(a)-1)
print(c[1][len(a)-1])
