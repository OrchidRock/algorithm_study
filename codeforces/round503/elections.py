lineone = input().split()
n = (int)(lineone[0])
m = (int)(lineone[1])

votecount = [0]*m
coin = [0]*n
coinvote = [0]*n
for i in range(0,n):
    secondline = input().split()
    p = (int)(secondline[0])
    c = (int)(secondline[1])
    votecount[p] += 1
    coin[i] = c
    coinvote[i] = p

