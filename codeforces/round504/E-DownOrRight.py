from sys import stdout
n = int(input())

def query(r1,c1,r2,c2):
    print("?"+" " + str(r1) + " "+str(c1) +" "+str(r2) +" "+str(c2))
    stdout.flush()
    ans = input()
    if ans == "YES":
        return True
    else:
        return False
row = n
col = n
res1 = []
while(row + col > n+1):
    if query(1,1,row,col-1):
        col -=1 # move left
        res1.insert(0,'R')
    else:
        row -=1
        res1.insert(0,'D')
row = 1
col = 1
res2=[]
while(row + col < n + 1):
    if query(row+1,col,n,n):
        row += 1
        res2.append('D')
    else:
        col +=1
        res2.append('R')

print('! ',end='')
for k in res2:
    print(k,end='')
for k in res1:
    print(k,end='')
print()
