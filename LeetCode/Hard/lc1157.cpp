#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class MajorityChecker {
private:
    int n, mn, mx;
    vector<vector<int>> tree;

    void merge(vector<int>& tot, vector<int>& a, vector<int>& b) {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) tot.push_back(a[i++]);
            else tot.push_back(b[j++]);
        }
        while (i < a.size()) tot.push_back(a[i++]);
        while (j < b.size()) tot.push_back(b[j++]);
    }

    void init(int node, int start, int end, vector<int>& arr) {
        if (start == end) {
            tree[node].push_back(arr[start]);
            return;
        }
        int mid = (start + end) >> 1;
        init(node << 1, start, mid, arr);
        init(node << 1 | 1, mid + 1, end, arr);
        merge(tree[node], tree[node << 1], tree[node << 1 | 1]);
    }

    int count(int node, int start, int end, int left, int right, int val) {
        if (end < left || right < start) return 0;
        if (left <= start && end <= right) 
            return upper_bound(tree[node].begin(), tree[node].end(), val) - tree[node].begin();
        int mid = (start + end) >> 1;
        return count(node << 1, start, mid, left, right, val)
                + count(node << 1 | 1, mid + 1, end, left, right, val);
    }
public:
    MajorityChecker(vector<int>& arr) {
        n = arr.size();
        int sz = 1;
        while (sz < n) sz <<= 1;
        tree.resize(sz << 1);
        init(1, 0, n - 1, arr);
        mn = 20000, mx = 0;
        for (int num: arr) {
            mn = min(mn, num);
            mx = max(mx, num);
        }
    }
    
    int query(int left, int right, int threshold) {
        int lo = mn, hi = mx;
        int len = right - left + 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int cnt = count(1, 0, n - 1, left, right, mid);
            if (2 * cnt > len) hi = mid - 1;
            else lo = mid + 1;
        }
        int vcnt = count(1, 0, n - 1, left, right, lo) - count(1, 0, n - 1, left, right, lo - 1);
        if (vcnt < threshold) lo = -1;
        return lo;
    }
};

int main(int argc, char *argv[]) {
    /* Input */
    vector<int> arr = {1, 1, 2, 2, 1, 1};
    MajorityChecker majorityChecker(arr);

    vector<vector<int>> queries = {
        {0, 5, 4},
        {0, 3, 3},
        {2, 3, 2}
    };

    /* Output */
    vector<int> ret;
    for (int i = 0; i < queries.size(); i++)
        ret.push_back(majorityChecker.query(queries[i][0], queries[i][1], queries[i][2]));

    /* Answer */
    vector<int> answer = {1, -1, 2};
    
    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
