A = [27,17,3,16,13,10,1,5,7,12,4,8,9,0]

#def printTree(A,h,i):
#    print(' '*h + str(A[i]))
#    print(' '*(h-1) + str(A[]) + str)

def maxHeapify(A,i,n):
    l = 2*i
    r = 2*i+1
    maxindex = i
    if l <=n and A[i-1] < A[l-1]:
        maxindex = l
    else:
        maxindex = i
    if r <= n and A[r-1] > A[maxindex-1]:
        maxindex = r
    if i != maxindex:
        tmp = A[i-1]
        A[i-1] = A[maxindex-1]
        A[maxindex-1] = tmp
        maxHeapify(A,maxindex,n)
def maxHeapifyInter(A,i,n):
    while 2*i <= n and (2*i+1) <=n :
        l = 2*i
        r = 2*i+1
        maxindex = i
        if l <=n and A[i-1] < A[l-1]:
            maxindex = l
        else:
            maxindex = i
        if r <= n and A[r-1] > A[maxindex-1]:
            maxindex = r
        if i != maxindex:
            tmp = A[i-1]
            A[i-1] = A[maxindex-1]
            A[maxindex-1] = tmp
            i = maxindex
        else:
            break
def buildMaxHeap(A,n):
    i = n//2
    while i >= 1:
        maxHeapify(A,i,n)
        i -= 1
    print(A)
def heapSort(A,n):
    buildMaxHeap(A,n)
    while n >= 2:
        tmp = A[n-1]
        A[n-1] = A[0]
        A[0] = tmp
        n -= 1
        maxHeapify(A,1,n)
print(A)    
#maxHeapify(A,3,len(A))
#maxHeapifyInter(A,3,len(A))
#buildMaxHeap(A,len(A))
heapSort(A,len(A))
print(A)
