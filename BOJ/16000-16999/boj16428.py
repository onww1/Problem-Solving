A = list(map(int, input().split()))
Q = A[0] // A[1]
R = A[0] % A[1]
if R < 0:
    if A[1] < 0:
        Q = Q + 1
        R = R - A[1]
    elif A[1] > 0:
        Q = Q - 1
        R = R + A[1]

print(Q)
print(R)