#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef long double ldb;

int main() {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    ldb m = (b - a) / 400.0;
    printf("%.12Lf\n", 1.0 / (1 + pow(10.0, m)));    
    return 0;
}