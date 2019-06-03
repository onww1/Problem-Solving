#include <algorithm>
#include <cstdio>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int MAX = 5e4 + 1;
int n, a, b;
pii c[MAX];
char in[3];

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 0; i < n; ++i) {
        scanf(" %s %d", in, &c[i].X);
        c[i].Y = (in[0] == 'S');
    }
    sort(c, c + n);

    int p = a - 1, ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        int next_mid = (c[i].X + c[i + 1].X) >> 1;
        int shared = 1 - (c[i].X + c[i + 1].X) % 2;
        if (next_mid > b) {
            next_mid = b;
            shared = 0;
        }
        if (next_mid <= p) continue;
        if (c[i].Y) ans += (next_mid - p);
        else if (shared && c[i + 1].Y) ans++;
        p = next_mid;
    }
    if (p < b && c[n - 1].Y) ans += (b - p); 
  
    printf("%d\n", ans);
    return 0;
}