a=[sum(map(int,input().split())) for _ in [0]*int(input())]
print(sum(x > a[0] for x in a[1:]) + 1)
