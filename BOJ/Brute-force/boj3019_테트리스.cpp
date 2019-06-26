#include <algorithm>
#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
int c, p, a[100];
int l[7][4] = {
    { 1, 4, INF, INF },
    { 2, INF, INF, INF },
    { 3, 2, INF, INF },
    { 3, 2, INF, INF },
    { 3, 2, 3, 2 },
    { 3, 2, 3, 2 },
    { 3, 2, 3, 2 }
              };
int b[7][4][4] = { 
    { {0, INF, INF, INF}, {0, 0, 0, 0}, {INF, INF, INF, INF}, {INF, INF, INF, INF} },
    { {0, 0, INF, INF}, {INF, INF, INF, INF}, {INF, INF, INF, INF}, {INF, INF, INF, INF} },
    { {0, 0, 1, INF}, {1, 0, INF, INF}, {INF, INF, INF, INF}, {INF, INF, INF, INF} },
    { {1, 0, 0, INF}, {0, 1, INF, INF}, {INF, INF, INF, INF}, {INF, INF, INF, INF} },
    { {0, 0, 0, INF}, {0, 1, INF, INF}, {1, 0, 1, INF}, {1, 0, INF, INF} },
    { {0, 0, 0, INF}, {0, 0, INF, INF}, {0, 1, 1, INF}, {2, 0, INF, INF} },
    { {0, 0, 0, INF}, {0, 2, INF, INF}, {1, 1, 0, INF}, {0, 0, INF, INF} }
                 };

int main(int argc, char *argv[]) {
    scanf("%d %d", &c, &p); p--;
    for (int i = 0; i < c; ++i) scanf("%d", a + i);

    int ans = 0;
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (c - i < l[p][j]) continue;
            int base = a[i] - b[p][j][0], f = 1;
            for (int k = 1; k < l[p][j]; ++k) 
                if (a[i + k] != base + b[p][j][k]) { f = 0; break; }
            if (f) ans++;
        }
    }
  
    printf("%d\n", ans);
    return 0;
}