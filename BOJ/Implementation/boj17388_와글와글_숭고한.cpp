#include <cstdio>
int main(int argc, char *argv[]) {
    int s, k, h;
    scanf("%d %d %d", &s, &k, &h);
    if (s + k + h >= 100) puts("OK");
    else if (s < k && s < h) puts("Soongsil");
    else if (k < s && k < h) puts("Korea");
    else puts("Hanyang");
    return 0;
}