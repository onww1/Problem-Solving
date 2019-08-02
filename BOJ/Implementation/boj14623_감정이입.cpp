#include <cstdio>
typedef long long ll;

char in1[35], in2[35];
ll a, b, c;

void binary(ll v) {
    if (v <= 1LL) {
        printf("%lld", v); 
        return;
    }
    binary(v / 2LL);
    printf("%lld", v % 2LL);
}

int main(int argc, char *argv[]) {
    scanf(" %s %s", in1, in2);
    for (int i = 0; in1[i]; ++i)
        a = 2LL * a + in1[i] - '0';
    for (int i = 0; in2[i]; ++i)
        b = 2LL * b + in2[i] - '0';
    c = a * b;
    binary(c); puts("");
    return 0;
}