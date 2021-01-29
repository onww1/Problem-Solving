#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <queue>
#include <deque>
using namespace std;

/* Solution Class */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Point {
    int val, y;
    Point(): Point(0, 0) {}
    Point(int _val, int _y): val(_val), y(_y) {}
    bool operator<(const Point& other) const {
        return y == other.y ? val < other.val : y > other.y;
    }
};

class Solution {
public:
    void traverse(TreeNode* node, deque<vector<Point>>& dq, int &mnx, int x, int y) {
        if (node == nullptr) return;
        if (x < mnx) {
            mnx = x;
            dq.push_front(vector<Point>());
        }
        if (x - mnx + 1 > dq.size()) {
            dq.push_back(vector<Point>());
        }
        dq[x - mnx].emplace_back(node->val, y);
        traverse(node->left, dq, mnx, x - 1, y - 1);
        traverse(node->right, dq, mnx, x + 1, y - 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        deque<vector<Point>> dq;
        int mnx = 0;
        traverse(root, dq, mnx, 0, 0);
        vector<vector<int>> answer;
        while (!dq.empty()) {
            vector<Point> v = dq.front();
            dq.pop_front();

            vector<int> p;
            sort(v.begin(), v.end());
            for (int i = 0; i < v.size(); i++) 
                p.push_back(v[i].val);
            answer.push_back(p);
        }
        return answer;
    }
};

TreeNode* make_tree(vector<int>& nodes);

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> nodes = {
        {3, 9, 20, -1, -1, 15, 7},
        {1, 2, 3, 4, 5, 6, 7}
    };
    vector<TreeNode*> root;
    for (int i = 0; i < nodes.size(); i++)
        root.push_back(make_tree(nodes[i]));

    /* Output */
    vector<vector<vector<int>>> ret;
    for (int i = 0; i < root.size(); i++)
        ret.push_back(solution.verticalTraversal(root[i]));

    /* Answer */
    vector<vector<vector<int>>> answer = {
        {{9}, {3, 15}, {20}, {7}},
        {{4}, {2}, {1, 5, 6}, {3}, {7}}
    };

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}

TreeNode* make_tree(vector<int>& nodes) {
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q; q.push(root);
    int idx = 1;
    while (!q.empty() && idx < nodes.size()) {
        TreeNode* node = q.front(); q.pop();
        if (nodes[idx] != -1) {
            node->left = new TreeNode(nodes[idx]);
            q.push(node->left);
        }
        idx++;
        if (nodes[idx] != -1) {
            node->right = new TreeNode(nodes[idx]);
            q.push(node->right);
        }
        idx++;
    }
    return root;
}