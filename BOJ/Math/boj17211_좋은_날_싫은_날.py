N, A = map(int, input().split())
P = list(map(float, input().split()))
C = [.0] * 4
C[A] = 1.

for i in range(N):
	C[2] = C[0] * P[0] + C[1] * P[2]
	C[3] = C[0] * P[1] + C[1] * P[3]
	C[0], C[1] = C[2], C[3]

like = int(C[0] * 10000)
dislike = int(C[1] * 10000)
if like % 10 >= 5: like = like // 10 + 1
else: like = like // 10
if dislike % 10 >= 5: dislike = dislike // 10 + 1
else: dislike = dislike // 10
print(like)
print(dislike)