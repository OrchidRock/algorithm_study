import sys
ADJ = [[2,4],[5],[5,6],[2],[4],[6]]

def bfs(ADJ,start,end,n): # 
    flag = [0 for i in range(0,n+1)]
    queue = [start]
    print(start,end=' ')
    while len(queue) > 0:
        u = queue.pop()
        if u == end:
            break
        for v in ADJ[u-1]:
            if flag[v] == 0:
                flag[v] = 1
                print(v,end=' ')
                if v == end:
                    queue = []
                    break
                queue.insert(0,v)
        flag[u] = 2
    print()
bfs(ADJ,int(sys.argv[1]),int(sys.argv[2]),len(ADJ))

