n = int(input())
reportlist = [int(key) for key in input().split()]
#print(reportlist)
hole = [0]*n
#print(hole)
for i in range(0,n):
    if reportlist[i] == (i+1):
        print(i+1)
    else:
        k = i
        hole = [0]*n
        while(True):
            if hole[k] > 1:
                break
            hole[k]+=1
            k = reportlist[k]-1
        print(k+1)
