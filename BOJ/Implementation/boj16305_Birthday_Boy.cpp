#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int N, M, D, days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector <int> V, ans;
char S[30];

int main(int argc, char *argv[]) {
    for (int i = 2; i <= 12; ++i) days[i] += days[i - 1];

    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf(" %s %d-%d", S, &M, &D);
        V.push_back(days[M - 1] + D);
    }

    sort(V.begin(), V.end());
    int mx = 365 + V[0] - V[V.size() - 1];
    ans.push_back(V[0] == 1 ? 365 : V[0] - 1);

    for (int i = 1; i < V.size(); ++i) {
        if (mx < V[i] - V[i - 1]) {
            mx = V[i] - V[i - 1];
            ans.clear();
            ans.push_back(V[i] - 1);
        } else if (mx == V[i] - V[i - 1]) 
            ans.push_back(V[i] - 1);
    }

    sort(ans.begin(), ans.end(), [](int a, int b) {
        a = (a + 64) % 365 + 1;
        b = (b + 64) % 365 + 1;
        return a < b;
    });

    for (int i = 0; i < 12; ++i) 
        if (days[i] < ans[0] && ans[0] <= days[i + 1]) {
            printf("%02d-%02d\n", i + 1, ans[0] - days[i]);
            break;
        }

    return 0;
}