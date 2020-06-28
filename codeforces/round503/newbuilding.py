firstline = input().split()
n = (int)(firstline[0])
h = (int)(firstline[1])
a = (int)(firstline[2])
b = (int)(firstline[3])
k = (int)(firstline[4])
for i in range(0,k):
    queries = input().split()
    ta = (int)(queries[0])
    fa = (int)(queries[1])
    tb = (int)(queries[2])
    fb = (int)(queries[3])
    if ta == tb:
        print(abs(fa-fb))
    else:
        if fa > b and fb > b:
            print(abs(ta-tb)+(fa-b)+(fb-b))
        elif fa < a and fb < a:
            print(abs(ta-tb)+(a-fa)+(a-fb))
        else:
            print(abs(ta-tb)+abs(fa-fb))

