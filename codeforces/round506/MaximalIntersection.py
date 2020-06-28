n = int(input())
left = []
right = []
a = []
b = []
for i in range(0,n):
    (l,r) = map(int,input().split())
    left.append(l)
    a.append(l)
    right.append(r)
    b.append(r)
left.sort()
right.sort()
ans = 0
for i in range(0,n):
    rindex = right.index(b[i])
    lindex = left.index(a[i])
    right.remove(b[i])
    left.remove(a[i])
    ans = max(ans,right[0]-left[len(left)-1])
    left.insert(lindex,a[i])
    right.insert(rindex,b[i])
print(ans)
