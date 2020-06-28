A = 'ACCGGTCGAGTGCGCGGAAGCCGGCCGAA'
B = 'GTCGTTCGGAATGCCGTTGCTCTGTAAA'

def lcs_length(A,B):
    m = len(A)
    n = len(B)
    c = [[0 for j in range(0,n+1)] for i in range(0,m+1)]
    b = [[0 for j in range(0,n+1)] for i in range(0,m+1)]
    for i in range(1,m+1):
        for j in range(1,n+1):
            if A[i-1] == B[j-1]:
                c[i][j] = c[i-1][j-1] + 1
                b[i][j] = 1
            elif c[i-1][j] >= c[i][j-1]:
                c[i][j] = c[i-1][j]
                b[i][j] = 2
            else:
                c[i][j] = c[i][j-1]
                b[i][j] = 3
    return (c,b)
def print_lcs(b,A,i,j):
    if i ==0 or j == 0:
        return
    if b[i][j] == 1:
        print_lcs(b,A,i-1,j-1)
        print(A[i-1],end='')
    elif b[i][j] == 2:
        print_lcs(b,A,i-1,j)
    else:
        print_lcs(b,A,i,j-1)

(c,b) = lcs_length(A,B)
print_lcs(b,A,len(A),len(B))
print()
print(c[len(A)][len(B)])
