import sys
import math
n = int(input())
s = int((n*(n+1))/2)

if n < 3:
    print("No")
    sys.exit(0)
A = [i for i in range(1,n+1)]
s1=[]
limit = math.ceil((s+1)/2)
for c in range(2,limit):
    if math.gcd(c,s-c) > 1:
        e = n
        while c > e:
            c = c - e
            s1.append(e)
            e -= 1
        s1.append(c)
        break
if len(s1) < 1 or len(s1) >=n :
    print("No")
    sys.exit(0)
print("Yes")
print(len(s1),end=' ')
for i in s1:
    print(i,end=' ')
print()
s2 = set(A) -set(s1)
print(len(s2),end=' ')
for i in s2:
    print(i,end=' ')
print()

                
            


