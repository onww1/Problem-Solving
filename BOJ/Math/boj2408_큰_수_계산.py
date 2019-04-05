N = int(input())
num, op = [], []
for idx in range(2 * N - 1):
	if idx % 2 == 0: num.append(int(input()))
	else: op.append(input())

idx = []
for i in range(len(op)):
	if op[i] == '*' or op[i] == '/': 
		idx.append(i)
		if op[i] == '*': num[i + 1] = num[i] * num[i + 1]
		elif op[i] == '/': num[i + 1] = num[i] // num[i + 1]

for i in range(len(idx) - 1, -1, -1):
	del op[idx[i]]
	del num[idx[i]]

for i in range(len(op)):
	if op[i] == '+': num[i + 1] = num[i] + num[i + 1]
	elif op[i] == '-': num[i + 1] = num[i] - num[i + 1]

print(num[-1])