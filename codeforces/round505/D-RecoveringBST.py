import math
n = int(input())
A = [int(key) for key in input().split()]
dp = [[[0 for k in range(0,n)] for i in range(0,n)] for j in range(0,n)]
print(dp)
def recoveringBST(A,i,j):
    for root in range(i,j+1):
        dpleft = (root==i)
        for l in range(i,root):
            if math.gcd(A[l],A[root]) > 1 and dp[l]
        for r in range(root+1,j+1):
        if dp[i][j][root] > 0:
            break


