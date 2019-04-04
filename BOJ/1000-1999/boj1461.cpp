/*
 *  BOJ 1461. 도서관
 *
 *  시간 복잡도 : O(NlogN)
 *  공간 복잡도 : O(N)
 *
 *  주어진 값들을 정렬하고, 절댓값이 가장 큰 값은 왕복이 아닌 편도(가장 마지막 루트)로 생각하고 cnt에 한 번만 더해줍니다.
 *  그리고 나머지는 최대한 절댓값이 큰 것끼리 묶어서 왕복한다고 생각해서 cnt를 계산합니다.
 *  한 마디로, 그리디 문제였습니다. ㅎㅎ
 */

#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 1e4;
int N, M, A[MAX];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) scanf("%d", A + i);
    sort(A, A + N);
    int idx = lower_bound(A, A + N, 0) - A; // 처음으로 양수가 되는 인덱스

    int l = 0, r = 0, cnt = 0;
    if (A[0] + A[N - 1] < 0) cnt = A[0] * -1, l = M, r = N - 1; // 음수가 더 클 때
    else cnt = A[N - 1], l = 0, r = N - M - 1;                  // 양수가 더 클 때
    for (; l < idx; l += M) cnt += A[l] * -2;   // 음수 부분을 그리디하게 가져감
    for (; r >= idx; r -= M) cnt += A[r] * 2;   // 양수 부분을 그리디하게 가져감
    
    printf("%d\n", cnt);
    return 0;
}
