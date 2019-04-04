/*
 *  BOJ 1577. 도로의 개수
 *
 *  시간 복잡도 : O(NM)
 *  공간 복잡도 : O(NM)
 *
 *  인접한 지역에 대해서 갈 수 있으면 자신의 경우의 수를 더해주는 식으로 DP를 했습니다.
 *  갈 수 없는 길은 cons라는 배열로 표시를 해서 계산하는 과정에서 가지 못하도록 했습니다.
 */

#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;

const int MAX = 1e2;
int N, M, K;
ll DP[MAX + 1][MAX + 1];
bool cons[2][MAX + 1][MAX + 1]; // 0 : 가로, 1 : 세로

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &M, &N, &K);
    for (int i = 0, row_a, col_a, row_b, col_b; i < K; ++i) {
        scanf("%d %d %d %d", &col_a, &row_a, &col_b, &row_b);
        if (row_a == row_b) {   // row가 같으면 가로로 이동하는 길이 막힘
            if (col_a > col_b) swap(col_a, col_b);
            cons[0][row_a][col_a] = true;
        }
        else if (col_a == col_b) {  // col이 같으면 세로로 이동하는 길이 막힘
            if (row_a > row_b) swap(row_a, row_b);
            cons[1][row_a][col_a] = true;
        }
    }

    DP[0][0] = 1;
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            if (j < M && !cons[0][i][j]) DP[i][j + 1] += DP[i][j];
            if (i < N && !cons[1][i][j]) DP[i + 1][j] += DP[i][j];
        }
    }
   
    printf("%lld\n", DP[N][M]);
    return 0;
}