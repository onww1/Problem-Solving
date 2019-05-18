#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int SZ = 1 << 17;
int N, M, A[SZ];
vector <int> tree[2 * SZ];

void init(int node, int start, int end) {
    if (start == end) {
        tree[node].push_back(A[start]);
        return;
    }

    int mid = (start + end) >> 1;
    init(2 * node, start, mid);
    init(2 * node + 1, mid + 1, end);

    int i = 0, j = 0;
    vector <int>& l = tree[2 * node], r = tree[2 * node + 1];
    while (i < l.size() && j < r.size()) {
        if (l[i] < r[j]) tree[node].push_back(l[i++]);
        else if (l[i] > r[j]) tree[node].push_back(r[j++]);
        else tree[node].push_back(l[i++]), tree[node].push_back(r[j++]);
    }
    while (i < l.size()) tree[node].push_back(l[i++]);
    while (j < r.size()) tree[node].push_back(r[j++]);
}

int count(int node, int start, int end, int left, int right, int val) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) {
        int idx = lower_bound(tree[node].begin(), tree[node].end(), val) - tree[node].begin();
        if (idx < tree[node].size() && tree[node][idx] == val) return idx + 1;
        else return idx; 
    }

    int mid = (start + end) >> 1;
    return count(node * 2, start, mid, left, right, val) + 
            count(node * 2 + 1, mid + 1, end, left, right, val);
}

int query(int left, int right, int val) {
    int cnt = count(1, 0, N - 1, left, right, val);
    return right - left + 1 - cnt;
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", A + i);
    init(1, 0, N - 1);

    scanf("%d", &M);
    while (M--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        printf("%d\n", query(a - 1, b - 1, c));
    }
  
    return 0;
}