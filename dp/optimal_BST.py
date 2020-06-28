#p = [0.15,0.10,0.05,0.10,0.20]
#q = [0.05,0.10,0.05,0.05,0.05,0.10]
p = [0.04,0.06,0.08,0.02,0.10,0.12,0.14]
q = [0.06,0.06,0.06,0.06,0.05,0.05,0.05,0.05]

MAXLONG = 2**63 + 1

def optimal_bst(p,q,n):
    e = [[0 for j in range(0,n+1)] for i in range(0,n+2)]
    w = [[0 for j in range(0,n+1)] for i in range(0,n+2)]
    root = [[0 for j in range(0,n+1)] for i in range(0,n+1)]
    
    for i in range(1,n+2):
        e[i][i-1] = q[i-1]
        w[i][i-1] = q[i-1]
    for l in range(1,n+1):
        for i in range(1,n-l+2):
            j = i+ l -1
            e[i][j] = MAXLONG
            w[i][j] = w[i][j-1] + p[j-1] + q[j]
            for r in range(i,j+1):
                t = e[i][r-1] + e[r+1][j] + w[i][j]
                if t < e[i][j]:
                    e[i][j] = t
                    root[i][j] = r
    return (e,root)
def print_optimal_bst(root,i,j,deep):
    if i > j:
        return
    r = root[i][j]
    print(deep*'-' + str(r))
    print(deep*'' + '|')
    print_optimal_bst(root,i,r-1,deep + 1)
    print_optimal_bst(root,r+1,j,deep + 1)
    
(e,root) = optimal_bst(p,q,len(p))
print_optimal_bst(root,1,len(p),0)
print(e[1][len(p)])
#print(root)
