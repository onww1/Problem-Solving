#include <algorithm>
#include <cstdio>
using namespace std;

int n, ans, a[50][9], player[9];
int bits[] = {0, 1, 1, 2, 1, 2, 2, 3};
int p[] = {3, 0, 1, 2, 4, 5, 6, 7, 8};

int simulation() {
    int score = 0, idx = 0;
    for (int inning = 0; inning < n; ++inning) {
        int out_cnt = 0, field = 0;
        while (out_cnt < 3) {
            int cur_action = a[inning][player[idx]];
            if (!cur_action) out_cnt++;
            else if (cur_action < 4) { 
                score += bits[field >> (3 - cur_action)]; 
                field = ((field << cur_action) | (1 << (cur_action - 1))) % 8;
            }
            else {
                score += bits[field] + 1;
                field = 0;
            }
            idx = (idx + 1) % 9;
        }
    }
    return score;
}

int main(int argc, char *argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 9; ++j)
            scanf("%d", a[i] + j);

    do {
        for (int i = 0; i < 9; ++i) player[p[i]] = i;
        ans = max(ans, simulation());
    } while (next_permutation(p + 1, p + 9));

    printf("%d\n", ans);
    return 0;
}