#include <algorithm>
#include <cstdio>
using namespace std;

char S[3][101];
int DP[101][101][101], L[3];

int main(int argc, char *argv[]) {
    scanf(" %s %s %s", S[0], S[1], S[2]);
    for (int i = 0; i < 3; ++i) for (L[i] = 0; S[i][L[i]]; ++L[i]);
    for (int i = 1; i <= L[0]; ++i) {
        for (int j = 1; j <= L[1]; ++j) {
            for (int k = 1; k <= L[2]; ++k) {
                if (S[0][i - 1] == S[1][j - 1] && S[1][j - 1] == S[2][k - 1]) 
                    DP[i][j][k] = DP[i - 1][j - 1][k - 1] + 1;
                else
                    DP[i][j][k] = max({DP[i - 1][j][k], DP[i][j - 1][k], DP[i][j][k - 1]});
            }
        }
    }

    printf("%d\n", DP[L[0]][L[1]][L[2]]);
    return 0;
}