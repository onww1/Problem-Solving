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
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        this->size = n;
        this->count.resize(2);
        this->count.assign(2, vector<int>(2 * n + 2, 0));
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int playerIndex = player - 1;
        if (++this->count[playerIndex][row] == this->size)
            return player;
        if (++this->count[playerIndex][this->size + col] == this->size)
            return player;
        if (row == col && ++this->count[playerIndex][this->size * 2] == this->size)
            return player;
        if (row + col == this->size - 1 && ++this->count[playerIndex][this->size * 2 + 1] == this->size)
            return player;
        return 0;
    }
    
private:
    int size;
    vector<vector<int>> count;
};

vector<int> simulation(int size, vector<vector<int>>& values) {
    vector<int> results;

    TicTacToe* ticTacToe = new TicTacToe(size);
    for (vector<int>& value: values) {
        int row = value[0];
        int col = value[1];
        int player = value[2];

        int result = ticTacToe->move(row, col, player);
        results.push_back(result);

        if (result > 0)
            break;
    }

    return results;
}

int main(int argc, char *argv[]) {
    /* Input */
    vector<int> size = {3};
    vector<vector<vector<int>>> values = {
        {{0, 0, 1}, {0, 2, 2}, {2, 2, 1}, {1, 1, 2}, {2, 0, 1}, {1, 0, 2}, {2, 1, 1}}
    };

    /* Output */
    vector<vector<int>> ret;
    for (int i = 0; i < size.size(); i++) 
        ret.push_back(simulation(size[i], values[i]));

    /* Answer */
    vector<vector<int>> answer = {
        {0, 0, 0, 0, 0, 0, 1}
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