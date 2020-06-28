# 商品1：重10kg，价值60$
A = [[10,60],[20,100],[30,120]]
n = 3 # 商品数量
W = 50 # 背包容量

def dp01KnapSack(A,n,W):
    c = [[0 for j in range(0,W+1)] for i in range(0,n+1)]
    s = []
    for i in range(1,n+1):
        for w in range(1,W+1):
            if A[i-1][0] <= w:
                if A[i-1][1] + c[i-1][w-A[i-1][0]] > c[i-1][w]:
                    c[i][w] = A[i-1][1] + c[i-1][w-A[i-1][0]]
                else:
                    c[i][w] = c[i-1][w]
            else:
                c[i][w] = c[i-1][w]
    i = n
    j = W
    while i >= 1 and j >= 1:
        if c[i][j] != c[i-1][j]:
            s.append(i)
            j -= A[i-1][0]
        i -= 1
    print(s)
    return c[n][W]
print(dp01KnapSack(A,n,W))
