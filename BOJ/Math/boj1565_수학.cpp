#include <cstdio>
int D, M, DA[50], GCD;

int _gcd(int a, int b) { return b ? _gcd(b, a % b) : a; }
bool check(int n) {
    bool ret = true;
    for (int i = 0; i < D; ++i) 
        if (n % DA[i]) {
            ret = false;
            break;
        }
    return ret;
}

int main() {
    scanf("%d %d", &D, &M);
    for (int i = 0; i < D; ++i) 
        scanf("%d", DA + i);
    scanf("%d", &GCD);
    for (int i = 1, A; i < M; ++i) {
        scanf("%d", &A);
        GCD = _gcd(GCD, A);
    }
    
    int ans = 0, i;
    for (i = 1; i * i < GCD; ++i) {
        if (GCD % i == 0) {
            if (check(i)) ans++;
            if (check(GCD / i)) ans++;
        }
    }
    if (i * i == GCD && check(i)) ans++;
    printf("%d\n", ans);
    return 0;
}