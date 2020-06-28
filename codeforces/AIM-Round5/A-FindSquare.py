(n,m) = map(int,input().split())
topleft = [-1,-1]
topright = [-1,-1]
bottomleft = [-1,-1]
bottomright = [-1,-1]

for i in range(0,n):
    column = input()
    for j in range(0,m):
        if column[j] == 'B':
            if topleft[0] == -1:
                topleft[0] = i
                topright[0] = i
                topleft[1] = j
                topright[1] = j
                bottomleft[0] = i
                bottomleft[1] = j
                bottomright[0] = i
                bottomright[1] = j
            else:
                bottomleft[0] = i
                bottomright[0] = i
                bottomright[1] =j
                topright[1] = j
print(topleft[0] + (bottomright[0] - topleft[0])//2 + 1)
print(bottomleft[1] + (bottomright[1] - topleft[1])//2 + 1)

