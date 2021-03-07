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
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        init(n, connections);
        vector<vector<int>> criticalConnections;
        dfs(0, -1, criticalConnections);
        return criticalConnections;
    }

private:
    int size, count;
    vector<int> discover;
    vector<vector<int>> edges;

    void init(int n, vector<vector<int>>& connections) {
        size = n;
        count = 0;
        discover.resize(size);
        discover.assign(size, 0);
        edges.resize(size);
        edges.assign(size, vector<int>());

        for (vector<int>& edge: connections) {
            edges[edge[0]].push_back(edge[1]);
            edges[edge[1]].push_back(edge[0]);
        }
    }

    int dfs(int node, int parent, vector<vector<int>>& criticalConnections) {
        int low = discover[node] = ++count;
        for (int next: edges[node]) {
            if (next == parent)
                continue;
            
            if (!discover[next]) {
                int minValue = dfs(next, node, criticalConnections);
                if (minValue > discover[node])
                    criticalConnections.push_back({node, next});
                low = min(low, minValue);
            } else {
                low = min(low, discover[next]);
            }
        }
        return low;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<int> nVec = {4};
    vector<vector<vector<int>>> connectionsVec = {
        {{0, 1}, {1, 2}, {2, 0}, {1, 3}}
    };

    /* Output */
    vector<vector<vector<int>>> ret;
    for (int i = 0; i < nVec.size(); i++)
        ret.push_back(solution.criticalConnections(nVec[i], connectionsVec[i]));

    /* Answer */
    vector<vector<vector<int>>> answer = {
        {{1, 3}}
    };

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