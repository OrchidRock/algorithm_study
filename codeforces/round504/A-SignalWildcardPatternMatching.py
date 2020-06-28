lineone = input().split(" ")
n = int(lineone[0])
m = int(lineone[1])
s = input()
t = input()

def doAction(n,m,s,t):
    if n > m+1:
        return False
    wildcardIndex = s.rfind('*')
    if wildcardIndex < 0:
        return s == t
    prefix = s[0:wildcardIndex] == t[0:wildcardIndex] 
    sufix = s[wildcardIndex+1:n] == t[wildcardIndex-n+1+m:m]
    w = t[wildcardIndex:wildcardIndex+m-n+1]
    wIsValid = (len(w) == 0) or (w.isalpha() and w.islower())
    #print(w)
    #print(wildcardIndex)
    #print(prefix)
    #print(s[wildcardIndex+1:n])
    #print(t[wildcardIndex-n+1+m:m])
    return prefix and sufix and wIsValid
if doAction(n,m,s,t):
    print("YES")
else:
    print("NO")

