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
    bool searchMatrixV1(vector<vector<int>>& matrix, int target) {
        // O(MlogN) 
        for (int i = 0; i < matrix.size(); i++) {
            int lo = 0, hi = (int)matrix[i].size() - 1;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                if (matrix[i][mid] == target)
                    return true;
                else if (matrix[i][mid] > target)
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
        }
        return false;
    }

    bool searchMatrixV2(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        return solve(0, n - 1, 0, m - 1, matrix, target);    
    }

    bool searchMatrixV3(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0, col = m - 1, lo, hi, mid;
        while (row < n && col >= 0) {
            lo = 0, hi = col;
            while (lo <= hi) {
                mid = (lo + hi) >> 1;
                if (matrix[row][mid] <= target)
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            col = hi;

            if (col < 0) 
                break;

            lo = row, hi = n - 1;
            while (lo <= hi) {
                mid = (lo + hi) >> 1;
                if (matrix[mid][col] >= target)
                    hi = mid - 1;
                else 
                    lo = mid + 1;
            }
            row = lo;

            if (row == n)
                break;
            
            if (matrix[row][col] == target)
                return true;
        }
        
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0, col = m - 1;
        while (row < n && col >= 0) {
            if (matrix[row][col] == target)
                return true;
            if (matrix[row][col] > target)
                col--;
            else
                row++;
        }
        return false;
    }

private:
    bool solve(int rlo, int rhi, int clo, int chi, vector<vector<int>>& matrix, int target) {
        if (rlo > rhi || clo > chi) return false;
        int rmid = (rlo + rhi) >> 1;
        int cmid = (clo + chi) >> 1;
        
        if (matrix[rmid][cmid] == target)
            return true;

        // get rid of bottom-right
        if (matrix[rmid][cmid] > target) {
            if (solve(rlo, rhi, clo, cmid - 1, matrix, target))
                return true;
            if (solve(rlo, rmid - 1, cmid, chi, matrix, target))
                return true;
        }
        // get rid of top-left
        else {
            if (solve(rlo, rhi, cmid + 1, chi, matrix, target))
                return true;
            if (solve(rmid + 1, rhi, clo, cmid, matrix, target))
                return true;
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<vector<int>>> matrix = {
        {
            {1, 4, 7, 11, 15},
            {2, 5, 8, 12, 19},
            {3, 6, 9, 16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
        },
        {
            {1, 4, 7, 11, 15},
            {2, 5, 8, 12, 19},
            {3, 6, 9, 16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
        }
    };
    vector<int> target = {5, 20};

    /* Output */
    vector<bool> ret;
    for (int i = 0; i < matrix.size(); i++)
        ret.push_back(solution.searchMatrix(matrix[i], target[i]));

    /* Answer */
    vector<bool> answer = {true, false};

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