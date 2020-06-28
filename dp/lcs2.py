A = 'ACCGGTCGAGTGCGCGGAAGCCGGCCGAA'
B = 'GTCGTTCGGAATGCCGTTGCTCTGTAAA'

def lcs_length(A,B):
    m = len(A)
    n = len(B)
    c = [[0 for j in range(0,n+1)] for i in range(0,m+1)]
    #b = [[0 for j in range(0,n+1)] for i in range(0,m+1)]
    for i in range(1,m+1):
        for j in range(1,n+1):
            if A[i-1] == B[j-1]:
                c[i][j] = c[i-1][j-1] + 1
                #b[i][j] = 1
            elif c[i-1][j] >= c[i][j-1]:
                c[i][j] = c[i-1][j]
                #b[i][j] = 2
            else:
                c[i][j] = c[i][j-1]
                #b[i][j] = 3
    return c
def print_lcs(c,A,i,j):
    if i ==0 or j == 0:
        return
    if c[i][j] == c[i-1][j]:
        print_lcs(c,A,i-1,j)
    elif c[i][j] == c[i][j-1]:
        print_lcs(c,A,i,j-1)
    elif c[i][j] == (c[i-1][j-1]+1):
        print_lcs(c,A,i-1,j-1)
        print(A[i-1],end='')
    else:
        pass

c = lcs_length(A,B)
print(c)
print_lcs(c,A,len(A),len(B))
print()
print(c[len(A)][len(B)])
