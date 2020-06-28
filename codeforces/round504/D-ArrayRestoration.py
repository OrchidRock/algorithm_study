import copy

lineone = input().split(" ")
n = int(lineone[0])
q = int(lineone[1])

a = [int(key) for key in input().split(' ')]
s = [[] for i in range(0,q+1)]


def doAction(n,q,a):
    for index in range(0,n):
        s[a[index]].append(index)

    #print(a)
    #print(s)
    if len(s[0]) == 0 and len(s[q]) == 0:
        return False
    for i in s[0]:
        for j in range(1,q+1):
            t = copy.deepcopy(s)            
            
    for i in range(q,-1,-1):
        for j in s[0]:
            if len(s[q]) == 0: 
                

if doAction(n,q,a):
    print("YES") 
    print(a)
else:
    print("NO")
