A = [13,19,9,5,12,8,7,4,21,2,6,11]

def partition(A,p,r):
    x = A[r]
    i = p-1
    for j in range(p,r):
        if A[j] <= x:
            i += 1
            tmp = A[i]
            A[i] = A[j]
            A[j] = tmp
    tmp = A[i+1]
    A[i+1] = A[r]
    A[r] = tmp
    return i+1
def quciksort(A,p,r):
    if p < r:
        q = partition(A,p,r)
        quciksort(A,p,q-1)
        quciksort(A,q+1,r)
print(A)
quciksort(A,0,len(A)-1)
print(A)
