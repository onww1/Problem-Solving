/*
 *  BOJ 17069. 파이프 옮기기 2
 *
 *  시간 복잡도 : O(N^2)
 *  공간 복잡도 : O(N^2)
 *
 *  [0 : 가로, 1 : 대각선, 2 : 세로]
 *  맨 처음에 DP[0][1][2] (한 쪽 끝이 (1,2)에 있고, 가로로 놓여 있는 상황)을 1로 해주고, 
 *  인접한 곳에 이동할 수 있으면 그 상황에 대한 DP항에 현재 항의 값을 더해주는 식으로 카운트 해준 다음
 *  마지막에 (N, N)의 항의 값들을 모두 더해서 출력하면 됐습니다.
 */

#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;

const int MAX = 32;
const int move_k[3] = {-1, 0, 1};
const int move_r[3] = {0, 1, 1};
const int move_c[3] = {1, 1, 0};
int N, A[MAX + 1][MAX + 1];
ll DP[3][MAX + 1][MAX + 1];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) scanf("%d", &A[i][j]);
    
    // 맨처음 상태에 대하여 1을 준다.
    DP[0][1][2] = 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (DP[k][i][j]) {  // 한쪽 끝이 (i, j)이고, 현재 상태가 k일 때의 경우가 있으면
                    for (int t = 0; t < 3; ++t) { 
                        int dk = k + move_k[t]; // 돌려본다.
                        if (dk < 0 || dk > 2) continue; // 돌릴 수 없으면 다음으로
                        int dr = i + move_r[dk], dc = j + move_c[dk];  // 해당 방향으로 이동한 칸의 인덱스
                        if (dr < 1 || dr > N || dc < 1 || dc > N) continue; // 불가능한 경우 다음으로
                        bool valid = true;
                        for (int a = i; a <= dr; ++a) 
                            for (int b = j; b <= dc; ++b)
                                if (A[a][b]) valid = false; 
                        if (!valid) continue;  // 인접한 칸이 갈 수 없으면 다음으로
                        DP[dk][dr][dc] += DP[k][i][j];  // 더해준다.
                    }
                }
            }
        }
    }

    printf("%lld\n", DP[0][N][N] + DP[1][N][N] + DP[2][N][N]);
    return 0;
}