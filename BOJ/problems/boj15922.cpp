#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N, x, y, last = -0x3f3f3f3f, sum = 0;
int main(int argc, char *argv[]) {
  
    scanf("%lld", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%lld %lld", &x, &y);
        if (last < x) {
            sum += (y - x);
            last = y;
        }
        else if (last < y) {
            sum += (y - last);
            last = y;
        }
    }

    printf("%lld\n", sum);
    return 0;
}