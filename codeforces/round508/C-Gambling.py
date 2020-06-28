n = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
A.sort()
B.sort()

sumA = 0
sumB = 0
while len(A) > 0 or len(B) > 0:
    if len(A) > 0:
        if len(B) < 1 or A[len(A)-1] >= B[len(B)-1]:
            sumA += A[len(A)-1]
            A.pop()
        else:
            B.pop()
    else:
        if len(B) > 0:
            B.pop()
    if len(B) > 0:
        if len(A) < 1 or B[len(B)-1] >= A[len(A)-1]:
            sumB += B[len(B)-1]
            B.pop()
        else:
            A.pop()
    else:
        if len(A) > 0:
            A.pop()
print(sumA-sumB)
