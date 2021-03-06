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
    int minSwapsCouples(vector<int>& row) {
        n = row.size();
        edges.resize(n / 2);
        edges.assign(n / 2, vector<int>());
        visited.resize(n / 2);
        visited.assign(n / 2, false);

        for (int i = 0; i < n; i += 2) {
            int groupA = row[i] / 2;
            int groupB = row[i + 1] / 2;
            if (groupA == groupB) {
                visited[groupA] = true;
                continue;
            }
            edges[groupA].push_back(groupB);
            edges[groupB].push_back(groupA);
        }

        int answer = 0;
        for (int i = 0; i * 2 < n; i++) 
            if (!visited[i]) {
                int clen = cycle_len(i, -1);
                answer += clen - 1;
            }
                
        
        return answer;
    }

private:
    int n;
    vector<vector<int>> edges;
    vector<bool> visited;

    int cycle_len(int node, int prev) {
        if (visited[node]) 
            return 0;
        visited[node] = true;
        for (int next: edges[node]) {
            if (next == prev) continue;
            return cycle_len(next, node) + 1;
        }
        return 1;
    }
};



int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> rows = {
        {0, 2, 1, 3},
        {3, 2, 0, 1}
    };

    /* Output */
    vector<int> ret;
    for (vector<int>& row: rows)
        ret.push_back(solution.minSwapsCouples(row));

    /* Answer */
    vector<int> answer = {1, 0};
    
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