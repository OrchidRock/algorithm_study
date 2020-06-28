ADJ = [[2,4],[5],[5,6],[2],[4],[6]]

ADM = [[0,1,0,1,0,0],
       [0,0,0,0,1,0],
       [0,0,0,0,1,1],
       [0,1,0,0,0,0],
       [0,0,0,1,0,0],
       [0,0,0,0,0,1]]

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
def convertADM(ADM,n):
    for i in range(0,n):
        for j in range(0,n):
            tmp = ADM[i][j]
            ADM[i][j] = ADM[j][i]
            ADM[j][i] = tmp
    return ADM

print(ADJ)
print(convertADJ(ADJ,len(ADJ)))
