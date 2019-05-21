#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;
typedef pair<int, pii> piii;

int N, iA, iB, depth[201], pa[201][8], in[201];
string A, B, R[101][2];
vector <string> idx;
vector <int> edges[201];

void init(int node, int parent) {
    depth[node] = depth[parent] + 1;
    pa[node][0] = parent;

    for (int i = 1; i < 8; ++i) {
        int tmp = pa[node][i - 1];
        pa[node][i] = pa[tmp][i - 1];
    }

    for (int next : edges[node]) 
        init(next, node);
}

piii LCA(int u, int v) {
    int anc = 0;
    pii dist = {0, 0};
    bool isSwapped = false;

    if (depth[u] < depth[v]) {
        isSwapped = true;
        swap(u, v);
    }

    for (int i = 7; i >= 0; --i) 
        if (depth[u] - depth[v] >= (1 << i)) {
            dist.X += (1 << i);
            u = pa[u][i];
        }

    if (u != v) {
        for (int i = 7; i >= 0; --i) {
            if (pa[u][i] != pa[v][i]) {
                dist.X += (1 << i);
                dist.Y += (1 << i);
                u = pa[u][i];
                v = pa[v][i];
            }
        }
        dist.X++;
        dist.Y++;
        anc = pa[u][0];
    }
    else anc = u;

    if (isSwapped) swap(dist.X, dist.Y);
    return {anc, dist};
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> A >> B;
    for (int i = 1; i <= N; ++i) {
        cin >> R[i][0] >> R[i][1];
        idx.push_back(R[i][0]);
        idx.push_back(R[i][1]);
    }
  
    sort(idx.begin(), idx.end());
    int L = unique(idx.begin(), idx.end()) - idx.begin();

    iA = lower_bound(idx.begin(), idx.end(), A) - idx.begin() + 1;
    iB = lower_bound(idx.begin(), idx.end(), B) - idx.begin() + 1;
    for (int i = 1; i <= N; ++i) {
        int idx_pa = lower_bound(idx.begin(), idx.end(), R[i][0]) - idx.begin() + 1;
        int idx_ch = lower_bound(idx.begin(), idx.end(), R[i][1]) - idx.begin() + 1;
        edges[idx_pa].push_back(idx_ch);
        in[idx_ch]++;
    }

    depth[0] = -1;
    for (int i = 1; i <= L; ++i)
        if (!in[i]) init(i, 0);

    piii val = LCA(iA, iB);

    if (val.X == 0) cout << "NOT RELATED" << '\n';
    else if (val.Y.X == 1 && val.Y.Y == 1) cout << "SIBLINGS" << '\n';
    else if ((val.Y.X == 0 && val.Y.Y > 0) || (val.Y.X > 0 && val.Y.Y == 0)) {
        int len = (val.Y.X == 0 ? val.Y.Y : val.Y.X);
        cout << (val.Y.X == 0 ? A : B) << " is the ";
        for (int i = 3; i <= len; ++i) cout << "great-";
        if (len > 1) cout << "grand-";
        cout << "mother of " << (val.Y.X == 0 ? B : A) << '\n';
    }
    else if ((val.Y.X == 1 && val.Y.Y > 1) || (val.Y.X > 1 && val.Y.Y == 1)) {
        int len = (val.Y.X == 1 ? val.Y.Y : val.Y.X);
        cout << (val.Y.X == 1 ? A : B) << " is the ";
        for (int i = 3; i <= len; ++i) cout << "great-";
        cout << "aunt of " << (val.Y.X == 1 ? B : A) << '\n';
    }
    else cout << "COUSINS" << '\n';

    return 0;
}