n = int(input())
Limit = 2000000002
a = list(map(int,input().split())) + [Limit]
#print(a)
maxnum = 1
lasti = 0
for i in range(1,n+1):
    if a[i] > (a[i-1]*2):
        maxnum = max(maxnum,i-lasti)
        lasti = i
print(maxnum)

