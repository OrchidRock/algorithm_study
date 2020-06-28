A = [5,10,4,1,22,17,16,21]

bst = [[A[0],-1,-1]]
def insert(bst,parent,a):
    if parent == -1:
        bst.append([a,-1,-1])
        return (len(bst)-1)
    if a > bst[parent][0]:
        bst[parent][2] = insert(bst,bst[parent][2],a)
        return parent
    else:
        bst[parent][1] = insert(bst,bst[parent][1],a)
        return parent
def inorderWalk(bst,x):
    if x != -1:
        inorderWalk(bst,bst[x][1])
        print(bst[x][0],end=' ')
        inorderWalk(bst,bst[x][2])
def minium(bst,x):
    ans = -1
    if x != -1:
        if bst[x][1] != -1:
            ans = minium(bst,bst[x][1])
        else:
            ans = bst[x][0]
    return ans
def maxum(bst,x):
    ans = -1
    if bst[x][2] != -1:
        ans = maxum(bst,bst[x][2])
    else:
        ans = bst[x][0]
    return ans
def successor(bst,x):
    if bst[x][2] != -1:
        return minium(bst,bst[x][2])
    
    

for i in range(1,len(A)):
    insert(bst,0,A[i])
print(bst)
inorderWalk(bst,0)
print()
print(minium(bst,0))
print(maxum(bst,0))
