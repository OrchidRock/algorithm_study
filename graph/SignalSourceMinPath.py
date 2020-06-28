
ADJ = [[0,-1,(6,2),(7,3)],
       [-1,-1,(8,3),(5,4),(-4,5)],
       [-1,-1,(-3,4),(9,5)],
       [-1,-1,(-2,2)],
       [-1,-1,(7,4),(2,1)]]

LIMIT = 1000000000

def InitializeSignalSource(ADJ,n):
    for i in range(1,n):
        ADJ[i][0] = LIMIT
        # ADJ[i][0] = 0  # Exercse 24.1-5

def relax(ADJ,u,v,w):
    if ADJ[v-1][0] > ADJ[u-1][0] + w:
        ADJ[v-1][0] = ADJ[u-1][0] + w
        ADJ[v-1][1] = u

def BellmanFord(ADJ,n,s):
    InitializeSignalSource(ADJ,n)
    for i in range(1,n):
        for j in range(1,n+1):
            l = len(ADJ[j-1])
            for k in range(2,l):
                v = ADJ[j-1][k][1]
                w = ADJ[j-1][k][0]
                relax(ADJ,j,v,w)
    
    for j in range(1,n+1):
        l = len(ADJ[j-1])
        for k in range(2,l):
            v = ADJ[j-1][k][1]
            w = ADJ[j-1][k][0]
            if ADJ[v-1][0] > ADJ[j-1][0] + w:
                return False
    return True
print(BellmanFord(ADJ,len(ADJ),1))
print(ADJ)
    
