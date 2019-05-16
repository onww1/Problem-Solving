#include <cstdio>
typedef long long ll;

int N;
char in[11];
ll dic[10], ans;

int main(int argc, char *argv[]) {
    scanf("%d %s", &N, in);

    dic[N - 1] = 1LL;
    for (int i = N - 2; i >= 0; --i) 
        dic[i] = 1LL + 26LL * dic[i + 1];

    for (int i = 0; in[i]; ++i)
        ans += dic[i] * (in[i] - 'a') + 1LL;

    printf("%lld\n", ans);
    return 0;
}