A = list(input().split())
fr, bk = A[0].split('.')
l = len(bk)
fr += bk
fr = int(fr)
b = int(A[1])
l = l * b
fr = fr ** b
string = str(fr)
l2 = len(string)
if l2 <= l:
  string = '0' * (l - l2 + 1) + string[:]
  l2 = len(string)
res = string[:l2 - l] + '.' + string[l2 - l:]
print(res)