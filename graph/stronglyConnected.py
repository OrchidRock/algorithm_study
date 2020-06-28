import sys
#! --*-- coding=utf-8 --*--
'''
    1 2 3 4 5 6 7 8 9 10
    q r s t u v w x y z
'''
node= ['','q','r','s','t','u','v','w','x','y','z']
ADJ = [[3,4,7],[5,9],[6],[8,9],[9],[7],[3],[10],[1],[8]]

def dfs(ADJ,i,time,flag):
    print(node[i],end=' ')
    time += 1
    flag[i][1] = time # start time
    flag[i][0] = 1 # gray
    for v in ADJ[i-1]:
        if flag[v][0] == 0: # 树边
            #print("("+node[i]+","+node[v]+")" + "tree edge")
            time = dfs(ADJ,v,time,flag)
        elif flag[v][0] == 1: # back edge
            #print("("+node[i]+","+node[v]+")" + "back edge")
            pass
        else:
            pass
            #print("("+node[i]+","+node[v]+")" + "other edge")

    time += 1
    flag[i][0] = 2
    flag[i][2] = time # finished time
    return time
def convertADJ(ADJ,n):
    adj = [[] for i in range(0,n+1)]
    for i in range(1,n+1):
        for key in ADJ[i-1]:
            if key != i:
                adj[key-1].append(i)
                for t in ADJ[key-1]:
                    if t == i: # 环
                        adj[i-1].append(key)
                        break
            else:  # 自循环
                adj[i-1].append(key)
    return adj    
def stronglyConnectedComponents(ADJ,n):
    # flag[i][3] i
    # flag[i][2] finished time
    # flag[i][1] start time
    # flag[i][0] color

    flag = [[0 for i in range(4)] for i in range(0,n+1)]
    for i in range(1,n+1):
        flag[i][3] = i
    time = 0
    for i in range(1,n+1): # first dfs
        if flag[i][0] == 0:
            time = dfs(ADJ,i,time,flag)
    AdJ_T = convertADJ(ADJ,n)
    print(AdJ_T)
    print(flag)
    def flagSortKey(e):
        return e[2]
    flag.sort(key=flagSortKey)
    print(flag)
    for i in range(1,n+1):
        flag[i][0] = 0
    for i in range(n,-1,-1):
        nodeNum = flag[i][3]
        if flag[nodeNum][0] == 0:
            print("--------")
            dfs(AdJ_T,nodeNum,time,flag)
            print()

     
stronglyConnectedComponents(ADJ,len(ADJ))

