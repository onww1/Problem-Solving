#include <cstdio>

int N, K, MOD;
int piece[11][8];
char in[9];

bool compare_pieces(int a, int b) {
    for (int va = 1 - N; va < N; ++va) {
        for (int ha = 1 - N; ha < N; ++ha) {
            for (int vb = 1 - N; vb < N; ++vb) {
                for (int hb = 1 - N; hb < N; ++hb) {
                    for (int row = 0; row < N; ++row) {
                        int aa = (va > row || row - va >= N) ? 0 : piece[a][row - va];
                        int bb = (vb > row || row - vb >= N) ? 0 : piece[b][row - vb];
                        if (ha < 0) aa <<= (-ha);
                        else aa >>= ha;
                        if (hb < 0) bb <<= (-hb);
                        else bb >>= hb;
                        aa %= MOD; bb %= MOD;
                        if (aa & bb || (aa | bb) ^ piece[0][row]) break;
                        if (row == N - 1) return true;
                    }
                }
            }
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &K);
    MOD = 1 << N;

    for (int i = 0; i <= K; ++i) 
        for (int j = 0; j < N; ++j) {
            scanf(" %s", in);
            for (int k = 0; in[k]; ++k) 
                piece[i][j] = piece[i][j] * 2 + (in[k] == '#');
        }
        
    for (int a = 1; a < K; ++a) {
        for (int b = a + 1; b <= K; ++b) {
            if (compare_pieces(a, b)) 
                return !printf("%d %d\n", a, b);
        }
    }

    return 0;
}