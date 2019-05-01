#include <algorithm>
#include <cstdio>
using namespace std;
typedef long double ldb;
const ldb ERR = 1e-10;
ldb p, c;

int main(int argc, char *argv[]) {
    scanf("%Lf", &p);
    while (1) {
        scanf("%Lf", &c);
        if (abs(c - 999.0) <= ERR) break;
        printf("%.2Lf\n", c - p);
        p = c;
    }
    return 0;
}