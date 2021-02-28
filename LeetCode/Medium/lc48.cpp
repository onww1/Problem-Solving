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
    /**
     *  n x n matrix
     *  (x') = (cos(90) -sin(90)) (x) = (0 -1) (x)
     *  (y') = (sin(90)  cos(90)) (y) = (1  0) (y)
     *  x' = -y, y' = x
     *
     *  x' = (-(2 * y - n + 1) + n - 1) / 2 = -y + n - 1
     *  y' = ((2 * x - n + 1) + n - 1) / 2 = x
     */
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int rowLimit = n / 2;
        int colLimit = (n + 1) / 2;
        for (int row = 0; row < rowLimit; row++) {
            for (int col = 0; col < colLimit; col++) {
                pair<int,int> point(row, col);
                for (int k = 0; k < 3; k++) {
                    point = rotatePoint(point, n);
                    swap(matrix[row][col], matrix[point.first][point.second]);
                }
            }
        }
    }

    pair<int,int> rotatePoint(pair<int,int> point, int n) {
        pair<int,int> nextPoint;
        nextPoint.second = -point.first + n - 1;
        nextPoint.first = point.second;
        return nextPoint;
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
            {5, 1, 9, 11},
            {2, 4, 8, 10},
            {13, 3, 6, 7},
            {15, 14, 12, 16}
        },
        {
            {1}
        },
        {
            {1, 2},
            {3, 4}
        }
    };

    /* Output */
    for (int i = 0; i < matrix.size(); i++)
        solution.rotate(matrix[i]);

    /* Answer */
    vector<vector<vector<int>>> answer = {
        {
            {7, 4, 1},
            {8, 5, 2},
            {9, 6, 3}
        },
        {
            {15, 13, 2, 5},
            {14, 3, 4, 1},
            {12, 6, 8, 9},
            {16, 7, 10, 11}
        },
        {
            {1}
        },
        {
            {3, 1},
            {4, 2}
        }
    };

    /* Check */
    assert(matrix == answer);

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