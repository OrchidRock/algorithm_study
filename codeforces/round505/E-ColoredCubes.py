(n,m) = map(int,input().split())
initpos = [[] for i in range(0,m+1)]
targetpos = [[] for i in range(0,m+1)]
for i in range(0,m):
    (x,y) = map(int,input().split())
    initpos[i+1].append(i+1)
    initpos[i+1].append(x)
    initpos[i+1].append(y)
for i in range(0,m):
    (x,y) = map(int,input().split())
    targetpos[i+1].append(i+1)
    targetpos[i+1].append(x)
    targetpos[i+1].append(y)

def arrangementBasic(pos,n,m):
    step = []
     
    return step
step1 = arrangementBasic(initpos)
step2 = arrangementBasic(targetpos)
print(len(step2) + len(step1) - 1)
for i in range(0,len(step1)):
    for j in range(0,4):
        print(str(step1[i][j])+" ",end='')
print()
for i in range(len(step2)-1,-1,-1):
    for j in range(2,4):
        print(str(step2[i][j])+" ",end='')
    for j in range(0,2):
        print(str(step2[i][j])+" ",end='')
print()
