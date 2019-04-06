while True:
  a, b, c, d = map(int, input().split())
  if a == 0 and b == 0 and c == 0 and d == 0: break
  a = a ** b 
  a = a ** c 
  a = a ** d 
  print(a)