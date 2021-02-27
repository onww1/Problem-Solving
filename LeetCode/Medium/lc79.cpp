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
    bool exist(vector<vector<char>>& board, string word) {
        numRow = board.size();
        numCol = board[0].size();
        visitCount = 0;
        visit.resize(numRow);
        visit.assign(numRow, vector<int>(numCol, 0));

        for (int row = 0; row < numRow; row++) {
            for (int col = 0; col < numCol; col++) {
                if (board[row][col] == word[0]) {
                    visitCount++;
                    if (find(row, col, 0, board, word))
                        return true;
                }
            }
        }

        return false;
    }

private:
    const int MOVE_ROW[4] = {-1, 1, 0, 0};
    const int MOVE_COL[4] = {0, 0, -1, 1};
    int numRow, numCol;
    int visitCount;
    vector<vector<int>> visit;

    bool isIn(int row, int col) {
        return 0 <= row && row < numRow && 0 <= col && col < numCol;
    }

    bool find(int row, int col, int idx, vector<vector<char>>& board, string& word) {
        if (idx + 1 == word.length())
            return true;

        visit[row][col] = visitCount;
        
        for (int k = 0; k < 4; k++) {
            int nextRow = row + MOVE_ROW[k];
            int nextCol = col + MOVE_COL[k];
            if (isIn(nextRow, nextCol) && visit[nextRow][nextCol] != visitCount && board[nextRow][nextCol] == word[idx + 1]) {
                if (find(nextRow, nextCol, idx + 1, board, word))
                    return true;
            }
        }

        visit[row][col] = 0;
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<vector<char>>> board = {
        {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
        },
        {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
        },
        {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
        },
        {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'E', 'S'},
            {'A', 'D', 'E', 'E'}
        }
    };

    vector<string> word = {
        "ABCCED",
        "SEE",
        "ABCB",
        "ABCESEEEFS"
    };

    /* Output */
    vector<bool> ret;
    for (int i = 0; i < board.size(); i++)
        ret.push_back(solution.exist(board[i], word[i]));

    /* Answer */
    vector<bool> answer = {true, true, false, true};

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