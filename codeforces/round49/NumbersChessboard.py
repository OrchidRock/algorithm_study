from math import floor,ceil
n,q = map(int,raw_input().split())
result=[]
for i in range(0,q):
    x,y = map(int,raw_input().split())
    x-=1
    y-=1
    r = ((x*n+y)/2)+1
    if (x+y)%2==1:
        r += ((n**2+1)/2)
    print(int(r))
