t = int(input())
for test_case in range(1, t+1):
  n = int(input())
  data = list(map(int, input().split()))
  mn = mx = data[0]
  for datum in data:
    mn = min(mn, datum)
    mx = max(mx, datum)
  print("#" + str(test_case) + " " + str(mx - mn))
