import sys
#! --*-- coding=utf-8 --*--
ADJ = [[2,3,4],[1,3,4],[1,2,4],[1,2,3,7],[6,7],[5,7],
       [4,5,6,8,9,11],[7,9],[7,8,10],[9],[7,12,13],
       [11,14],[11,14],[12,13,15],[14,16,21],[15,17,18,21],
       [16,19,20],[16],[17,20],[17,19],[15,16]]

def dfsVisit(ADJ,i,time,flag):
    time += 1
    flag[i][1] = time # start time
    flag[i][0] = 1 # gray
    flag[i][4] = flag[i][1] # v.low = v.d
    # flag[i][5] 标记是否为衔接点
    # flag[i][4] 记录low值
    isleaf = True
    for v in ADJ[i-1]:
        if flag[v][0] == 0: # 树边
            isleaf = False
            flag[v][3] = i
            time = dfsVisit(ADJ,v,time,flag)
            flag[i][4] = min(flag[i][4],flag[v][4])
            if flag[i][1] <= flag[v][4]:
                flag[i][5] = 1
                #flag[i][5] = max(flag[i][5],flag[v][5])
        else: # back edge
            if flag[i][3] == v: # 
               pass 
            elif flag[i][1] > flag[v][1]:
                flag[i][4] = min(flag[i][4],flag[v][1]) # 一条边不能既是树边又是后向边，因此这里要加以判断
                #flag[i][5] = min(flag[i][5],flag[v][1])
    if isleaf:
        flag[i][5] = 0 # 叶子节点不可能是衔接点
        #p = flag[i][3]
        #flag[i][4] = min(flag[i][4],flag[p][1])
    elif flag[i][4] == flag[i][1]:
        pass
        #flag[i][5] = 1
    time += 1
    flag[i][0] = 2
    flag[i][2] = time # finished time
    return time
def articulationPoint(ADJ,n):
    flag = [[0 for i in range(6)] for i in range(0,n+1)]
    time = 0
    for i in range(1,n+1):
        if flag[i][0] == 0:
            time = dfsVisit(ADJ,i,time,flag)
    print(flag) 
    rchildcount = 0
    for j in range(2,n+1):
        if flag[j][5] :
            print(j)
        if flag[j][3] == 1: # root's child
            rchildcount += 1
    if rchildcount > 1:
        print(1)
     

articulationPoint(ADJ,len(ADJ))
