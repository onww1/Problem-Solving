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
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        numRow = grid.size();
        numCol = grid[0].size();
        vector<vector<bool>> visit(numRow, vector<bool>(numCol, false));

        int maxArea = 0;
        for (int row = 0; row < numRow; row++) {
            for (int col = 0; col < numCol; col++) {
                if (grid[row][col] == 1 && !visit[row][col]) {
                    int area = getArea(row, col, grid, visit);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }

private:
    const int MOVE_ROW[4] = {-1, 1, 0, 0};
    const int MOVE_COL[4] = {0, 0, -1, 1};
    int numRow, numCol;

    int getArea(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visit) {
        if (!grid[row][col] || visit[row][col])
            return 0;

        int area = 0;
        queue<pair<int,int>> que;
        que.emplace(row, col);
        visit[row][col] = true;

        while (!que.empty()) {
            int curRow = que.front().first;
            int curCol = que.front().second;
            que.pop();

            area++;
            for (int k = 0; k < 4; k++) {
                int nextRow = curRow + MOVE_ROW[k];
                int nextCol = curCol + MOVE_COL[k];
                if (nextRow < 0 || nextRow >= numRow || nextCol < 0 || nextCol >= numCol) 
                    continue;
                if (grid[nextRow][nextCol] && !visit[nextRow][nextCol]) {
                    que.emplace(nextRow, nextCol);
                    visit[nextRow][nextCol] = true;
                }
            }
        }

        return area;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<vector<int>>> grid = {
        {
            {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0, 0, 0, 0}
        }
    };

    /* Output */
    vector<int> ret;
    for (int i = 0; i < grid.size(); i++)
        ret.push_back(solution.maxAreaOfIsland(grid[i]));

    /* Answer */
    vector<int> answer = {6, 0};

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