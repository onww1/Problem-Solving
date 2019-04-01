P = 'joke'
F = [0, 0, 0, 0]

# calculate Failure Function
j = 0
for i in range(1, 4):
	while j > 0 and P[i] != P[j]:
		j = F[j - 1]
	if P[i] == P[j]:
		j += 1
		F[i] = j

# matching
cnt = 0
while True:
	try:
		T = input()
	except:
		break

	j, L = 0, len(T)
	for i in range(L):
		while j > 0 and T[i] != P[j]:
			j = F[j - 1]
		if T[i] == P[j]:
			if j == 3:
				cnt += 1
				j = F[j]
			else:
				j += 1

print(cnt)