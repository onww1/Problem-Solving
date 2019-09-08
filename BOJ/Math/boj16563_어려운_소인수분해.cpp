#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;

int n, k, factor[5000001];
char ans[1000];

int main(int argc, char *argv[]) {
    for (int i = 2; i * i <= 5000000; ++i)
        if (!factor[i])
            for (int j = i * i; j <= 5000000; j += i)
                if (!factor[j])
                    factor[j] = i;

    scanf("%d", &n);
    for (int i = 0, len; i < n; ++i) {
        scanf("%d", &k);
        len = 0;
        while (factor[k]) {
            len += sprintf(ans + len, "%d ", factor[k]);
            k /= factor[k];
        }
        len += sprintf(ans + len, "%d\n", k);
        ans[len] = 0;
        printf("%s", ans);
    }

    return 0;
}