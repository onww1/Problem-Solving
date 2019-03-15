/*
 *  BOJ 2980. 도로와 신호등
 *
 *  시간 복잡도 : O(N)
 *  공간 복잡도 : O(1)
 *
 *  각 신호등 인풋에 대해서 신호등까지 이동, 현재 시간 계산 후 처리만 해주면 됩니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int N, L, D, R, G, T, DIST;
int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &L);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d %d", &D, &R, &G);
        // 현재 위치에서 신호등까지 이동
        T += D - DIST;
        DIST = D;

        // 신호등 기준으로 현재 시간이 어떤 신호인지 알아내기.
        int curT = T % (R + G);

        // 모듈러한 값이 빨간 불에 해당하면 초록불 신호까지 시간 기다리기.
        if (0 <= curT && curT < R) T += R - curT;
    }

    // 도착점까지 거리가 남아있으면 이동시키기
    if (DIST < L) T += L - DIST;
    printf("%d\n", T);
    return 0;
}