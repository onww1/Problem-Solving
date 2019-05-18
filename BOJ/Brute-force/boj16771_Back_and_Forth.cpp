#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

int FB[15], SB[15];
set <int> S;

void solve(int day, int first, int second) {
    if (day == 4) {
        S.insert(first);
        return;
    }

    if (day % 2) {
        int lim = 10 + (day + 1) / 2;
        for (int i = 0; i < lim; ++i) {
            if (SB[i] != -1) {
                int tmp = SB[i];
                SB[i] = -1;
                FB[10 + day / 2] = tmp;
                solve(day + 1, first + tmp, second - tmp);
                SB[i] = tmp;
            }
        }
    } else {
        int lim = 10 + day / 2;
        for (int i = 0; i < lim; ++i) {
            if (FB[i] != -1) {
                int tmp = FB[i];
                FB[i] = -1;
                SB[10 + day / 2] = tmp;
                solve(day + 1, first - tmp, second + tmp);
                FB[i] = tmp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    for (int i = 0; i < 10; ++i) scanf("%d", FB + i);
    for (int i = 0; i < 10; ++i) scanf("%d", SB + i);

    solve(0, 1000, 1000);
    printf("%lu\n", S.size());
  
    return 0;
}