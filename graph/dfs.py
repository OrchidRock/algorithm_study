import sys
#! --*-- coding=utf-8 --*--
'''
    1 2 3 4 5 6 7 8 9 10
    q r s t u v w x y z
'''
node= ['','q','r','s','t','u','v','w','x','y','z']
ADJ = [[3,4,7],[5,9],[6],[8,9],[9],[7],[3],[10],[1],[8]]

flag = [[0 for i in range(3)] for i in range(0,len(ADJ)+1)]
def dfsVisit(ADJ,i,time):
    time += 1
    flag[i][1] = time # start time
    flag[i][0] = 1 # gray
    for v in ADJ[i-1]:
        if flag[v][0] == 0: # 树边
            print("("+node[i]+","+node[v]+")" + "tree edge")
            time = dfsVisit(ADJ,v,time)
        elif flag[v][0] == 1: # back edge
            print("("+node[i]+","+node[v]+")" + "back edge")
        else:
            if flag[v][1] > flag[i][1]:
                print("("+node[i]+","+node[v]+")" + "forward edge")
            else:
                print("("+node[i]+","+node[v]+")" + "cross edge")

    time += 1
    flag[i][0] = 2
    flag[i][2] = time # finished time
    return time
def dfs(ADJ,n):
    time = 0
    for i in range(1,n+1):
        if flag[i][0] == 0:
            time = dfsVisit(ADJ,i,time)
    
    

dfs(ADJ,len(ADJ))
print(flag)
