lineone = input().split(" ")
n = int(lineone[0])
k = int(lineone[1])
#print(n)
#print(k)
def countpairs(n,k):
    if k > (n + n -1):
        return 0
    limit = k // 2
    if k<=n:
        return k-limit-1
    else:
        return (n-limit)
    
print(countpairs(n,k))
    
