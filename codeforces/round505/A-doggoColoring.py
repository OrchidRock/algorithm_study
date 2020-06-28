n = int(input())
s = input()

def go(n,s):
    if n == 1:
        return "YES"
    l = [0 for i in range(0,26)]
    for i in range(0,n):
        index = ord(s[i]) - ord('a')
        l[index] += 1
        if l[index] >= 2:
            return "YES"
    return "NO"
print(go(n,s))
