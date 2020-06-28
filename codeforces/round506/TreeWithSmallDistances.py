import sys

def bfs(ADJ,n): # 
    flag = [0 for i in range(0,n+1)]
    queue = [(1,1)]
    s = [0 for i in range(0,n+1)]
    s[1] = 1
    sn = 1
    while len(queue) > 0:
        (u,d) = queue.pop()
        sn = d
        for v in ADJ[u]:
            if flag[v] == 0:
                flag[v] = 1
                queue.insert(0,(v,d+1))
                s[d+1] += 1
        flag[u] = 2
    return (s,sn)
n = int(input())
ADJ = [[] for i in range(0,n+1)]
for i in range(n-1):
    (u,v) = map(int,input().split())
    ADJ[u].append(v)
    ADJ[v].append(u) 

(s,sn) = bfs(ADJ,n)
ans = 0
while sn > 3:
    ans += s[sn-1]
    k = int((sn)/2)
    for i in range(1,k+1):
        s[i+1] += s[sn-i]
    sn -= 2
print(ans)

