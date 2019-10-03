#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;

const int MAX = 1e5 + 1;
ll n, t, a[MAX];

int main(int argc, char *argv[]) {
    scanf("%lld %lld", &n, &t);
    for (ll i = 0, p, s; i < n; ++i) {
        scanf("%lld %lld", &p, &s);
        a[i] = p + s * t;
    }

    vector <ll> lis;
    lis.push_back(0x7fffffffffffffff);
    for (int i = n - 1; i >= 0; --i) {
        if (lis.back() <= a[i]) lis.push_back(a[i]);
        else {
            auto it = upper_bound(lis.begin(), lis.end(), a[i]);
            *it = a[i];
        }
    }

    printf("%lu\n", lis.size());
    return 0;
}