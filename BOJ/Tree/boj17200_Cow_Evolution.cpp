#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef pair <int, int> pii;

const int MAX = 25;
const int MOD = 1e9 + 7;

int hashing(char *str) {
    int ret = 0;
    for (int i = 0; str[i]; ++i) 
        ret = (1LL * ret * 10007 + str[i] - 'a') % MOD;
    return ret;
}

int N, K, C, color[MAX], cnt[MAX * MAX + 1];
char feature[MAX];
vector <int> f[MAX * MAX + 1];
map <int, int> idx;
priority_queue <pii> pq;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &K);
        for (int j = 0; j < K; ++j) {
            scanf(" %s", feature);
            int hash = hashing(feature);
            int &val = idx[hash];
            if (val == 0) val = ++C;
            f[val].push_back(i);
            cnt[val]++;
        }
    }

    for (int feat = 1; feat <= C; ++feat) 
        pq.push({cnt[feat], feat});

    while (!pq.empty()) {
        int feat = pq.top().second;
        pq.pop();

        int cc = -1;
        for (int idx : f[feat]) {
            if (cc == -1) cc = color[idx];
            else if (cc != color[idx]) return !printf("no\n");
            color[idx] = feat;
        }
    }

    bool visited[MAX * MAX + 1]{};
    for (int i = 0; i < N; ++i) {
        if (visited[color[i]]) return !printf("no\n");
        visited[color[i]] = true;
    }

    puts("yes");
    return 0;
}
