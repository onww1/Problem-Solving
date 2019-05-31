#include <cstdio>
#include <vector>
using namespace std;

char in, str[] = "BIGOESM";
int N, idx[128];
vector <int> V[8];

int main(int argc, char *argv[]) {
    for (int i = 0; i < 7; ++i) idx[str[i]] = i + 1;

    scanf("%d", &N);
    for (int i = 0, v; i < N; ++i) {
        scanf(" %c %d", &in, &v);
        V[idx[in]].push_back(v);
    }

    int tot = 1;
    for (int i = 1; i <= 7; ++i) tot *= (int)V[i].size();

    int odd[3]{};
    for (int i = 0; i < V[1].size(); ++i) 
        for (int j = 0; j < V[2].size(); ++j)
            if ((V[1][i] + V[2][j]) % 2) odd[0]++;
    for (int i = 0; i < V[3].size(); ++i)
        for (int j = 0; j < V[4].size(); ++j)
            for (int k = 0; k < V[5].size(); ++k)
                for (int l = 0; l < V[6].size(); ++l)
                    if ((V[3][i] + V[4][j] + V[5][k] + V[6][l]) % 2) odd[1]++;
    for (int i = 0; i < V[7].size(); ++i)
        if (V[7][i] % 2) odd[2]++;

    tot -= odd[0] * odd[1] * odd[2];
    printf("%d\n", tot);
    return 0;
}