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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = makeGraph(numCourses, prerequisites);
        vector<int> order = topologicalSort(numCourses, graph);
        return order;
    }

private:
    vector<vector<int>> makeGraph(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>());
        for (vector<int>& edge: edges) 
            graph[edge[1]].push_back(edge[0]);
        return graph;
    }

    vector<int> topologicalSort(int n, vector<vector<int>>& graph) {
        vector<int> indegree(n, 0);
        for (int node = 0; node < n; node++)
            for (int next: graph[node])
                indegree[next]++;
        
        queue<int> que;
        for (int node = 0; node < n; node++)
            if (!indegree[node])
                que.push(node);

        vector<int> order;
        while (!que.empty()) {
            int node = que.front();
            que.pop();

            order.push_back(node);

            for (int next: graph[node]) 
                if (!--indegree[next]) 
                    que.push(next);
        }

        if (order.size() < n)
            order.clear();
        return order;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<int> numCourses = {2, 4, 1};
    vector<vector<vector<int>>> prerequisites = {
        {{1, 0}},
        {{1, 0}, {2, 0}, {3, 1}, {3, 2}},
        {}
    };

    /* Output */
    vector<vector<int>> ret;
    for (int i = 0; i < numCourses.size(); i++)
        ret.push_back(solution.findOrder(numCourses[i], prerequisites[i]));

    /* Answer */
    vector<vector<int>> answer = {
        {0, 1},
        {0, 2, 1, 3},
        {0}
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