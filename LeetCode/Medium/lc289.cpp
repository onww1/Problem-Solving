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
    void gameOfLife(vector<vector<int>>& board) {
        numRow = board.size();
        numCol = board[0].size();
        countAdjacentLiveCell(board);
        updateBoard(board);
    }

private:
    const int MOVE_ROW[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int MOVE_COL[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int numRow, numCol;

    void countAdjacentLiveCell(vector<vector<int>>& board) {
        for (int row = 0; row < numRow; row++) {
            for (int col = 0; col < numCol; col++) {
                if (board[row][col] % 10) {
                    for (int k = 0; k < 8; k++) {
                        int nextRow = row + MOVE_ROW[k];
                        int nextCol = col + MOVE_COL[k];
                        if (nextRow < 0 || nextRow >= numRow || nextCol < 0 || nextCol >= numCol)
                            continue;
                        board[nextRow][nextCol] += 10;
                    }
                }
            }
        }
    }

    void updateBoard(vector<vector<int>>& board) {
        for (int row = 0; row < numRow; row++) {
            for (int col = 0; col < numCol; col++) {
                int currentStatus = board[row][col] % 10;
                int adjacentLiveCells = board[row][col] / 10;
                if (canLive(currentStatus, adjacentLiveCells))
                    board[row][col] = 1;
                else
                    board[row][col] = 0;
            }
        }
    }

    bool canLive(int currentStatus, int adjacentLiveCells) {
        return (currentStatus == 1 && 2 <= adjacentLiveCells && adjacentLiveCells <= 3)
               || (currentStatus == 0 && adjacentLiveCells == 3);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<vector<int>>> board = {
        {
            {0, 1, 0},
            {0, 0, 1},
            {1, 1, 1},
            {0, 0, 0}
        },
        {
            {1, 1},
            {1, 0}
        }
    };

    /* Output */
    for (int i = 0; i < board.size(); i++)
        solution.gameOfLife(board[i]);

    /* Answer */
    vector<vector<vector<int>>> answer = {
        {
            {0, 0, 0},
            {1, 0, 1},
            {0, 1, 1},
            {0, 1, 0}
        },
        {
            {1, 1},
            {1, 1}
        }
    };

    /* Check */
    assert(board == answer);

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