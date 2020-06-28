n=int(input())
m=int(n**0.5)

arr = [list() for i in range((n+m-1)//m)]
print(arr)
ind = -1
for i in range(n):
    if i%m == 0:
        ind +=1
    arr[ind].append(i+1)
print(arr)
for i in arr[::-1]:
    for j in i:
        print(j)
