/*
 *	BOJ 1614. 영식이의 손가락
 *
 *	시간 복잡도 : O(1)
 *	공간 복잡도 : O(1)
 *
 *	단순 계산 문제입니다.
 */

#include <cstdio>
int S, N;
int main() {
    scanf("%d %d", &S, &N);
    if (S == 1 || S == 5) printf("%lld\n", 8LL * N + S - 1);
    else printf("%lld\n", 8LL * (N / 2) + (N % 2 ? 9 - S : S - 1));
    return 0;
}