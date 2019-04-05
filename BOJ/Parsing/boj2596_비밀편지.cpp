#include <algorithm>
#include <cstdio>
using namespace std;
int alpha[8] = { 0b000000, 0b001111, 0b010011, 0b011100,
                 0b100110, 0b101001, 0b110101, 0b111010 };
int N, idx;
char in[61], ans[11];

int main(int argc, char *argv[]) {
    scanf("%d %s", &N, in);
    for (int i = 0, val = 0, j; in[i]; ++i) {
        val = val * 2 + in[i] - '0';
        if (i % 6 == 5) {
            for (j = 0; j < 8; ++j) {
                int bit = alpha[j] ^ val;
                if (bit == 0 || (bit & -bit) == bit) {
                    ans[idx++] = 'A' + j;
                    break;
                }
            }
            if (j == 8) return !printf("%d\n", i / 6 + 1);
            val = 0;
        }
    }

    ans[idx] = 0;
    printf("%s\n", ans);
    return 0;
}