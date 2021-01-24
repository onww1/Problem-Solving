#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    void merge(vector<int> &p, vector<int> &l, vector<int> &r) {
        int lp = 0, rp = 0;
        while (lp < l.size() && rp < r.size()) {
            if (l[lp] < r[rp]) p.push_back(l[lp++]);
            else p.push_back(r[rp++]);
        }
        while (lp < l.size()) p.push_back(l[lp++]);
        while (rp < r.size()) p.push_back(r[rp++]);
    }

    void init(int node, int start, int end, vector<vector<int>> &tree, vector<pair<long long,int>> &psum) {
        if (start == end) {
            tree[node].push_back(psum[start].second);
            return;
        }
        int mid = (start + end) >> 1;
        init(node << 1, start, mid, tree, psum);
        init(node << 1 | 1, mid + 1, end, tree, psum);
        merge(tree[node], tree[node << 1], tree[node << 1 | 1]);
    }

    int count(int node, int start, int end, int left, int right, int value, vector<vector<int>> &tree) {
        if (end < left || right < start) return 0;
        if (left <= start && end <= right) {
            int num = std::upper_bound(tree[node].begin(), tree[node].end(), value) - tree[node].begin();
            return num;
        }
        int mid = (start + end) >> 1;
        return count(node << 1, start, mid, left, right, value, tree)
                + count(node << 1 | 1, mid + 1, end, left, right, value, tree);
    }

    int lower_bound(vector<pair<long long,int>> &psum, long long target) {
        int lo = 0, hi = (int)psum.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (psum[mid].first >= target) hi = mid - 1;
            else lo = mid + 1;
        }
        return lo;
    }

    int upper_bound(vector<pair<long long,int>> &psum, long long target) {
        int lo = 0, hi = (int)psum.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (psum[mid].first > target) hi = mid - 1;
            else lo = mid + 1;
        }
        return lo;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        if (!n) return 0;
        vector<pair<long long,int>> psum(n);
        psum[0].first = nums[0];
        for (int i = 1; i < n; i++) {
            psum[i].second = i;
            psum[i].first = psum[i - 1].first + nums[i];
        }
        sort(psum.begin(), psum.end());
        int sz = 1;
        while (sz < n) sz <<= 1;
        vector<vector<int>> tree(2 * sz, vector<int>());
        this->init(1, 0, n - 1, tree, psum);

        int answer = 0;
        for (int i = 0; i < psum.size(); i++) {
            long long lv = lower + psum[i].first;
            long long rv = upper + psum[i].first;
            int lbidx = this->lower_bound(psum, lv);
            int ubidx = this->upper_bound(psum, rv);
            if (ubidx <= lbidx) continue;
            answer += (ubidx - lbidx) - this->count(1, 0, n - 1, lbidx, ubidx - 1, psum[i].second, tree);
        }

        int lbidx = this->lower_bound(psum, lower);
        int ubidx = this->upper_bound(psum, upper);
        if (ubidx > lbidx) answer += (ubidx - lbidx);

        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> nums = {
        {-2, 5, -1},
        {2147483647, -2147483648, -1, 0}
    };
    vector<int> lower = {-2, -1};
    vector<int> upper = {2, 0};

    /* Output */
    vector<int> ret;
    for (int i = 0; i < nums.size(); i++)
        ret.push_back(solution.countRangeSum(nums[i], lower[i], upper[i]));

    /* Answer */
    vector<int> answer = {3, 4};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
