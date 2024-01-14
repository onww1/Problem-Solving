import sys
import itertools


def Input():
    global N, cost, discount
    N = int(input())
    cost = list(map(int, input().split()))
    discount = {}
    for i in range(N):
        p = int(input())
        discount[i] = []
        for j in range(p):
            target, discount_amount = map(int, input().split())
            discount[i].append((target - 1, discount_amount))


def Solution():
    global N, cost, discount, answer
    answer = sys.maxsize

    for order in itertools.permutations(range(N)):
        _cost = cost.copy()
        total_cost = 0
        for num in order:
            total_cost += _cost[num]
            for target, discount_amount in discount[num]:
                _cost[target] = max(1, _cost[target] - discount_amount)
        answer = min(answer, total_cost)


def Output():
    global answer
    print(answer)


if __name__ == '__main__':
    Input()
    Solution()
    Output()
