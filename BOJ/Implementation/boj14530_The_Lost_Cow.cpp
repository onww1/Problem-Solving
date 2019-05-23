#include <cstdio> 

int main(int argc, char *argv[]) {
    int x, y, d = 1, ans = 0;
    scanf("%d %d", &x, &y);
    for (int i = 0; 1; ++i, d *= 2) {
        if (i % 2) {
            if (x - d <= y && y <= x) {
                ans += x - y;
                break;
            }
            else ans += 2 * d;
        }
        else {
            if (x <= y && y <= x + d) {
                ans += y - x;
                break;
            }
            else ans += 2 * d;
        }
    }

    printf("%d\n", ans);
    return 0;
}