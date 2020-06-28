(n,k) = map(int,input().split())
a = list(map(int,input().split()))
count = 0
def remainder(p,shift,k):
    p = p % k
    for i in range(0,shift):
        p = (p * 10) % k
    return p
for i in range(0,n):
    for j in range(0,n):
        if i != j:
            shift = len(str(a[j]))
            #p = (a[i]*(10**shift)) % k
            p = remainder(a[i],shift,k)
            q = a[j] % k
            if (p + q) % k == 0:
                count += 1
print(count)
