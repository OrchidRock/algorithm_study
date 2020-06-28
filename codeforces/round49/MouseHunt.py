n = int(input())
c = list(map(int,input().split()))
a = list(map(int,input().split()))



def dfs(ADj,c,i,k,flag):
    flag[i][0] = 1
    v = ADj[i] - 1
    if flag[v][1] != 0:
        flag[i][1] = flag[v][1]
    else:
        flag[v][1] = k
    knum = flag[i][1]
    mincost = c[i]
    if flag[v][0] == 0:
        (mincost,knum) = dfs(ADj,c,v,k,flag)
    elif flag[v][0] == 1: # ring
        pass
    else:
        pass
    mincost = min(mincost,c[i])
    flag[i][1] = knum
    return (mincost,flag[i][1]) 

flag = [[0,0] for i in range(0,n)]
k = 1
result = [0 for i in range(0,n+1)]
for i in range(0,n):
    for j in range(0,n):
        flag[j][0] = 0
    #flag[i][1] = k
    (mincost,knum) = dfs(a,c,i,k,flag)
    #print(mincost,end=' ')
    #print(knum)
    result[knum] = max(result[knum],mincost)
    if knum == k:
        k += 1
        
#print(result)
print(sum(result))
