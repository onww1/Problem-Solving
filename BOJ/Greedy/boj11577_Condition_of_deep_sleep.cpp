#include <cstdio>

const int MAX = 1e5;
int N, K, ans, S[MAX + 1], tree[MAX + 1];

void update(int node) {
    while (node <= MAX) {
        tree[node] += 1;
        node += node & -node;
    }
}

int sum(int node) {
    if (node <= 0) 
        return 0;

    int ret = 0;
    while (node) {
        ret += tree[node];
        node -= node & -node;
    }
    return ret;
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; ++i) scanf("%d", S + i);
    for (int i = 1; i <= N - K + 1; ++i) {
        int flip = (sum(i - 1) - sum(i - K)) % 2;
        if (S[i] ^ flip) {
            ans++;
            update(i);
        }
    }

    bool flag = 1;
    for (int i = N - K + 2; i <= N; ++i) {
        int flip = (sum(i - 1) - sum(i - K)) % 2;
        if (S[i] ^ flip) {
            flag = 0;
            break;
        }
    }

    if (flag) printf("%d\n", ans);
    else puts("Insomnia");

    return 0;
}