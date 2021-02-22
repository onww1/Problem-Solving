#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

ListNode* makeList(vector<int>& nodes);
TreeNode* makeTree(vector<int>& nodes);
bool matchList(ListNode* anode, ListNode* bnode);
bool matchTree(TreeNode* anode, TreeNode* bnode);

const int EMPTY = 0x7f7f7f7f;

/* Solution Class */
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target)
            return 0;

        vector<vector<int>> edges(routes.size(), vector<int>());
        vector<bool> visit(routes.size(), false);
        unordered_set<int> targetSet;
        queue<pair<int,int>> que;

        for (int i = 0; i < routes.size(); i++) {
            sort(routes[i].begin(), routes[i].end());
            if (contain(routes[i], source)) {
                que.emplace(i, 1);
                visit[i] = true;
            }
            if (contain(routes[i], target))
                targetSet.insert(i);
        }

        for (int i = 0; i < routes.size(); i++)
            for (int j = i + 1; j < routes.size(); j++)
                if (intersect(routes[i], routes[j])) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }

        while (!que.empty()) {
            int route = que.front().first;
            int dist = que.front().second;
            que.pop();

            if (targetSet.count(route))
                return dist;

            for (int next: edges[route]) {
                if (visit[next]) continue;
                visit[next] = true;
                que.emplace(next, dist + 1);
            }
        }

        return -1;
    }

private:
    bool intersect(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) 
                return true;
            if (a[i] < b[j]) 
                i++;
            else
                j++;
        }
        return false;
    }

    bool contain(vector<int>& a, int target) {
        int lo = 0, hi = (int)a.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (a[mid] <= target) lo = mid + 1;
            else hi = mid - 1;
        }
        return hi >= 0 && a[hi] == target;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<vector<int>>> routes = {
        {{1, 2, 7}, {3, 6, 7}},
        {{7, 12}, {4, 5, 15}, {6}, {15, 19}, {9, 12, 13}}
    };
    vector<int> source = {1, 15};
    vector<int> target = {6, 12};

    /* Output */
    vector<int> ret;
    for (int i = 0; i < routes.size(); i++)
        ret.push_back(solution.numBusesToDestination(routes[i], source[i], target[i]));

    /* Answer */
    vector<int> answer = {2, -1};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}

ListNode* makeList(vector<int>& nodes) {
    if (nodes.empty())
        return nullptr;

    ListNode* head = new ListNode(nodes[0]);
    ListNode* ptr = head;
    for (int i = 1; i < nodes.size(); i++) {
        ptr->next = new ListNode(nodes[i]);
        ptr = ptr->next;
    }

    return head;
}

TreeNode* makeTree(vector<int>& nodes) {
    if (nodes.empty())
        return NULL;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> que;
    que.push(root);

    int idx = 1;
    while (!que.empty() && idx < nodes.size()) {
        TreeNode* node = que.front();
        que.pop();

        if (nodes[idx] != EMPTY) {
            node->left = new TreeNode(nodes[idx]);
            que.push(node->left);
        }
        idx++;

        if (nodes[idx] != EMPTY) {
            node->right = new TreeNode(nodes[idx]);
            que.push(node->right);
        }
        idx++;
    }

    return root;
}

bool matchList(ListNode* anode, ListNode* bnode) {
    while (anode && bnode) {
        if (anode->val != bnode->val)
            return false;
        anode = anode->next;
        bnode = bnode->next;
    }
    return !anode && !bnode;
}

bool matchTree(TreeNode* anode, TreeNode* bnode) {
    if (!anode && !bnode) 
        return true;
    if (!anode || !bnode)
        return false;
    if (anode->val != bnode->val)
        return false;
    return matchTree(anode->left, bnode->left) && matchTree(anode->right, bnode->right);
}