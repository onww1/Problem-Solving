A = input()
num = 0
for i in A:
    num = num * 2 + int(i)
num = num * 17
ans = ''
while num > 0:
  ans += str(num % 2)
  num = num // 2
ans = ans[::-1]
print(ans)