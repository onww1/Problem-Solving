for _ in range(3):
    N = int(input())
    sum = 0
    for _ in range(N):
        a = int(input())
        sum += a
    if sum > 0 : print('+')
    elif sum < 0 : print('-')
    else : print('0')