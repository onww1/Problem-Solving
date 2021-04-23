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
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        if (!n) return "";

        vector<int> left(n, INF);
        if (dominoes[n - 1] == 'L') left[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (dominoes[i] == 'L') left[i] = 0;
            else if (dominoes[i] == 'R') left[i] = INF;
            else if (left[i + 1] != INF) left[i] = left[i + 1] + 1;
        }

        string answer = "";
        int curVal = (dominoes[0] != 'R') * INF;
        if (curVal < left[0]) answer += "R";
        else if (left[0] < curVal) answer += "L";
        else answer += ".";

        for (int i = 1; i < n; i++) {
            if (dominoes[i] == 'R') curVal = 0;
            else if (dominoes[i] == 'L') curVal = INF;
            else if (curVal != INF) curVal++;

            if (curVal < left[i]) answer += "R";
            else if (left[i] < curVal) answer += "L";
            else answer += ".";
        }

        return answer;
    }

private:
    const int INF = 0x3f3f3f3f;
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<string> dominoesVec = {
        ".L.R...LR..L..",
        "RR.L"
    };

    /* Output */
    vector<string> ret;
    for (string& dominoes: dominoesVec)
        ret.push_back(solution.pushDominoes(dominoes));

    /* Answer */
    vector<string> answer = {
        "LL.RR.LLRRLL..",
        "RR.L"
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