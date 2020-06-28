#A = [30,35,15,5,10,20,25]
A = [5,10,3,12,5,50,6]
maxLong = 2**63 -1

def matrix_chain_order(A):
    n = len(A) - 1
    m = [[0 for j in range(0,n+1)] for i in range(0,n+1)]
    s = [[0 for j in range(0,n+1)] for i in range(0,n+1)]
    for l in range(2,n+1):
        for i in range(1,n-l+2):
            j = i + l -1
            m[i][j] = maxLong
            for k in range(i,j):
                q = m[i][k] + m[k+1][j] + A[i-1]*A[k]*A[j]
                if q < m[i][j]:
                    m[i][j] = q
                    s[i][j] = k
    return (m[1][n],s)
def print_optimal_parens(s,i,j):
    if i == j:
        print("A"+str(i),end='')
    else:
        print("(",end='')
        print_optimal_parens(s,i,s[i][j])
        print_optimal_parens(s,s[i][j]+1,j)
        print(")",end='')

(result,s) = matrix_chain_order(A)
print(result)
print_optimal_parens(s,1,len(A)-1)
print()
