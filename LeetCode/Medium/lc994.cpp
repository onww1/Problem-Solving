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
    int orangesRotting(vector<vector<int>>& grid) {
        numRow = grid.size();
        numCol = grid[0].size();
        freshCount = 0;

        queue<pair<int,int>> que;
        for (int row = 0; row < numRow; row++) {
            for (int col = 0; col < numCol; col++) {
                if (grid[row][col] == FRESH)
                    freshCount++;
                else if (grid[row][col] == ROTTEN) 
                    que.emplace(row, col);
            }
        }

        if (!freshCount)
            return 0;

        int t = -1, qSize = 0;
        while (!que.empty()) {
            if (qSize <= 0) {
                qSize = que.size();
                t++;
            }
            while (qSize--) {
                int row = que.front().first;
                int col = que.front().second;
                que.pop();

                for (int k = 0; k < 4; k++) {
                    int dr = row + move_r[k];
                    int dc = col + move_c[k];
                    if (dr < 0 || dr >= numRow || dc < 0 || dc >= numCol)
                        continue;
                    if (grid[dr][dc] == FRESH) {
                        grid[dr][dc] = ROTTEN;
                        que.emplace(dr, dc);
                        freshCount--;
                    }
                }
            }
        }

        return !freshCount ? t : -1;
    }

private:
    const int move_r[4] = {-1, 1, 0, 0};
    const int move_c[4] = {0, 0, -1, 1};
    const int NONE = 0;
    const int FRESH = 1;
    const int ROTTEN = 2;
    int numRow, numCol, freshCount;
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<vector<int>>> grid = {
        {
            {2, 1, 1},
            {1, 1, 0},
            {0, 1, 1}
        },
        {
            {2, 1, 1},
            {0, 1, 1},
            {1, 0, 1}
        },
        {
            {0, 2}
        }
    };

    /* Output */
    vector<int> ret;
    for (int i = 0; i < grid.size(); i++) 
        ret.push_back(solution.orangesRotting(grid[i]));

    /* Answer */
    vector<int> answer = {4, -1, 0};
    for (int i = 0; i < ret.size(); i++) printf("%d vs %d\n", ret[i], answer[i]);
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