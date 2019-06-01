#include <cstdio>

int convert_base_to_dec(int n, int base) {
    return (n / 100) * base * base + (n / 10) % 10 * base + n % 10;
}

int main(int argc, char *argv[]) {
    int k, a, b;
    scanf("%d", &k);
    while (k--) {
        scanf("%d %d", &a, &b);
        for (int x = 10, f = 1; f && x <= 15000; ++x) {
            int dec_a = convert_base_to_dec(a, x);
            int l = 10, r = 15000;
            while (l <= r) {
                int mid = (l + r) >> 1;
                int dec_b = convert_base_to_dec(b, mid);
                if (dec_a == dec_b) {
                    printf("%d %d\n", x, mid); f = 0;
                    break;
                }
                else if (dec_a > dec_b) l = mid + 1;
                else r = mid - 1;
            }
        }
    }
    return 0;
}