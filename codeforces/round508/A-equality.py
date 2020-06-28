import sys
(n,k) = map(int,input().split())
s = input()
c = [0 for i in range(0,k)]

for j in s:
    i = ord(j) - ord('A')
    c[i] += 1
ans = 0
minc = 100005
for i in range(0,k):
    if c[i] == 0:
        print(0)
        sys.exit(0)
    minc = min(minc,c[i])
print(minc*k)
