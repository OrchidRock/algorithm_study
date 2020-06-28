import sys
ADJ = [[2,4],[5],[5,6],[2],[4],[6]]

flag = [0 for i in range(0,len(ADJ)+1)]

def dfsVisit(ADJ,i):
    flag[i] = 1
    print(i)
    for v in ADJ[i-1]:
        if flag[v] == 0:
            dfsVisit(ADJ,v)
def dfs(ADJ,n):
    for i in range(1,n+1):
        if flag[i] == 0:
            dfsVisit(ADJ,i)
    
    

dfs(ADJ,len(ADJ))

