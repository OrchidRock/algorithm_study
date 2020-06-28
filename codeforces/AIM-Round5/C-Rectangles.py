n = int(input())
columnLeft = []
columnRight = []
rowLeft = []
rowRight = []

def sortKey(e):
    return e[1]
def findKey(A,i):
    for j in range(0,len(A)):
        if A[j][0] == i:
            return (A[j][1],j)
    return 0
for i in  range(0,n):
    (x1,y1,x2,y2) = map(int,input().split())
    columnLeft.append([i,y1])
    columnRight.append([i,y2])
    rowRight.append([i,x2])
    rowLeft.append([i,x1])
columnLeft.sort(key=sortKey)
columnRight.sort(key=sortKey)
rowLeft.sort(key=sortKey)
rowRight.sort(key=sortKey)
ansx = 0
ansy = 0
for i in range(0,n):
    (y1,clindex) = findKey(columnLeft,i)
    (y2,crindex) = findKey(columnRight,i)
    (x1,rlindex) = findKey(rowLeft,i)
    (x2,rrindex) = findKey(rowRight,i)
    columnRight.remove(columnRight[crindex])
    columnLeft.remove(columnLeft[clindex])
    rowRight.remove(rowRight[rrindex])
    rowLeft.remove(rowLeft[rlindex])
    if columnRight[0][1] >= columnLeft[n-2][1] and rowRight[0][1] >= rowLeft[n-2][1]:
        ansy = columnRight[0][1]
        ansx = rowRight[0][1]
        #print("ok")
        break
    columnRight.insert(crindex,[i,y2])
    columnLeft.insert(clindex,[i,y1])
    rowRight.insert(rrindex,[i,x2])
    rowLeft.insert(rlindex,[i,x1])
print(ansx)
print(ansy)

