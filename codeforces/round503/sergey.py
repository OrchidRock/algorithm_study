firstline=input().split()
n=(int)(firstline[0])
m=(int)(firstline[1])

vertices=[[]]*n
print(vertices)
for i in range(0,m):
    secondline=input().split()
    beginpoint=(int)(secondline[0])
    endpoint =(int)(secondline[1])
    #print(beginpoint)
    #print(endpoint)
    point = vertices[beginpoint-1]
    point.append(endpoint-1)
    vertices[beginpoint-1] = point
print(vertices)

