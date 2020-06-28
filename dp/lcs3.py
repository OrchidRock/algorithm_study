'''
由c数组的输出可知，带备忘的递归算法与自底向上的算法相比，少计算了很多子问题
'''

A = 'ACCGGTCGAGTGCGCGGAAGCCGGCCGAA'
B = 'GTCGTTCGGAATGCCGTTGCTCTGTAAA'

m = len(A)
n = len(B)
c = [[0 for j in range(0,n+1)] for i in range(0,m+1)]

recount = 0

def lcs_length(A,B,i,j):
    if i==0 or j ==0 :
        return 0
    if c[i][j] > 0:
        return c[i][j]
    if A[i-1] == B[j-1]:
        c[i][j] =  lcs_length(A,B,i-1,j-1) + 1
    else:
        c[i][j] = max(lcs_length(A,B,i,j-1),lcs_length(A,B,i-1,j))
    return c[i][j]

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
lcs_length(A,B,m,n)
print(c[m][n])
print_lcs(c,A,m,n)
print()
print("recount="+str(recount)+",mn="+str(m*n))
