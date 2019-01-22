tc = int(input())
for _ in range(tc):
    n = int(input())
    sum, gpa = 0, 0.0
    for _ in range(n):
        i = input().split()
        c = int(i[0])
        g = float(i[1])
        sum += c
        gpa += (g * c)
    print(sum, round(gpa/sum, 1))
