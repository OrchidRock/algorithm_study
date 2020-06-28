A = '41056978'

def lis_length(A):
    n = len(A)
    p = [1 for i in range(0,n+1)]
    for i in range(1,n+1):
        for j in range(1,i): # 使用二分查找进行优化
            if A[j-1] < A[i-1]:
                p[i] = max(p[i],p[j]+1)
        #p[i] = max(p[i],p[i-1])
        #print("p["+str(i)+"] = "+str(p[i]))
    return p
p = lis_length(A)
print(max(p))
