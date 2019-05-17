#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
using namespace std;
typedef pair <int, int> pii;

const int MOD = 1e9 + 7;
int N, K, C, ans;
set <int> animals[100];
map <pii, int> idx;
char in[21];

int hashing1(char *str) {
    int ret = 0;
    for (int i = 0; str[i]; ++i)
        ret = (1LL * ret * 10007 + str[i] - 'a') % MOD;
    return ret;
}

int hashing2(char *str) {
    int ret = 0;
    for (int i = 0; str[i]; ++i)
        ret = (1LL * ret * 10009 + str[i] - 'a') % MOD;
    return ret;
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf(" %s %d", in, &K);
        for (int j = 0; j < K; ++j) {
            scanf(" %s", in);
            int hash1 = hashing1(in);
            int hash2 = hashing2(in);
            int &val = idx[pii(hash1, hash2)];
            if (!val) val = ++C;
            animals[i].insert(val);
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            int cnt = 0;
            for (auto it = animals[i].begin(); it != animals[i].end(); ++it) 
                if (animals[j].count(*it) > 0) 
                    ++cnt;
            if (animals[i].size() > cnt) cnt++;
            ans = max(ans, cnt);
        }
    }

    printf("%d\n", ans);
    return 0;
}