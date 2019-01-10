#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#define MOD 1000000007LL
#define INF 1023456789LL
using namespace std;

typedef long long ll;
typedef double db;

ll get_pow(ll base, ll exp);

int a[100050];
int main(int argc, char *argv[]) {
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n ; ++i) scanf("%d", &a[i]);
    sort(a, a+n);
    if (n == 2) return !printf("0\n");
    return !printf("%d\n", min(a[n-1] - a[1], a[n-2] - a[0]));
}

ll get_pow(ll base, ll exp) {
    ll ret = 1LL;
    while (exp > 0) {
        if (exp % 2) {
            ret *= base;
            ret %= MOD;
        }
        base *= base;
        base %= MOD;
        exp /= 2;
    }
    return ret;
}
