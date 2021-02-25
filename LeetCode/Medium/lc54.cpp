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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int numRow = matrix.size();
        int numCol = matrix[0].size();
        int rowLow = 0, rowHigh = numRow - 1;
        int colLow = 0, colHigh = numCol - 1;
        vector<int> answer;

        while (1) {
            if (!isValidRange(rowLow, rowHigh, colLow, colHigh)) break;
            for (int col = colLow; col <= colHigh; col++)
                answer.push_back(matrix[rowLow][col]);
            rowLow++;

            if (!isValidRange(rowLow, rowHigh, colLow, colHigh)) break;
            for (int row = rowLow; row <= rowHigh; row++)
                answer.push_back(matrix[row][colHigh]);
            colHigh--;

            if (!isValidRange(rowLow, rowHigh, colLow, colHigh)) break;
            for (int col = colHigh; col >= colLow; col--)
                answer.push_back(matrix[rowHigh][col]);
            rowHigh--;

            if (!isValidRange(rowLow, rowHigh, colLow, colHigh)) break;
            for (int row = rowHigh; row >= rowLow; row--)
                answer.push_back(matrix[row][colLow]);
            colLow++;
        }

        return answer;
    }

private:
    bool isValidRange(int rowLow, int rowHigh, int colLow, int colHigh) {
        return rowLow <= rowHigh && colLow <= colHigh;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<vector<int>>> matrix = {
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        },
        {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
        }
    };

    /* Output */
    vector<vector<int>> ret;
    for (int i = 0; i < matrix.size(); i++)
        ret.push_back(solution.spiralOrder(matrix[i]));

    /* Answer */
    vector<vector<int>> answer = {
        {1, 2, 3, 6, 9, 8, 7, 4, 5},
        {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7}
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