lineone = input().split(" ")
n = int(lineone[0])
k = int(lineone[1])

bracket = input()
stack = []
limit = (int)((n-k)/2)
count = 0
for key in bracket:
    if key == '(':
        stack.append(key)
    elif key == ')':
        if count < limit:
            stack.pop()
            count += 1
        else:
            stack.append(key)
    #print(stack)
print(''.join(stack)) 
