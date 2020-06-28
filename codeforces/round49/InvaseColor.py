MOD = 998244353

(n,k) = map(int,input().split())
dp = [[0 for j in range(0,n+5)] for i in range(0,n+5)]

result = 0
dp[0][0] = 1
for i in range(0,n):
    for j in range(0,i+1):
        for t in range(i+1,n+1):
            dp[t][max(j,t-i)] = (dp[t][max(j,t-i)] + dp[i][j])%MOD

for i in range(1,n+1):
    for j in range(1,n+1):
        if i*j < k:
            result = (result + dp[n][i]*dp[n][j]) % MOD
print((result*2) % MOD)

