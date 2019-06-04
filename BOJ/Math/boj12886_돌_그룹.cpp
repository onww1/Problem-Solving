#include <cstdio>

int _gcd(int a, int b) { return b ? _gcd(b, a % b) : a; }

int main(int argc, char *argv[]) {
    int A, B, C;  
    scanf("%d %d %d", &A, &B, &C);
    int V = (A + B + C) / _gcd(A, _gcd(B, C));
    if (V % 3 == 0 && V / 3 > 0 && ((V / 3) & (V / 3 - 1)) == 0) puts("1");
    else puts("0");
    return 0;
}