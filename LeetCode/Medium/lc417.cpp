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
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> answer;
        if (matrix.empty() || matrix[0].empty())
            return answer;

        numRow = matrix.size();
        numCol = matrix[0].size();
        vector<vector<int>> status(numRow, vector<int>(numCol, 0));
        queue<pair<int,int>> q;

        for (int i = 0; i < numRow; i++) {
            q.emplace(i, 0);
            status[i][0] |= 1;
        }
        for (int j = 1; j < numCol; j++) {
            q.emplace(0, j);
            status[0][j] |= 1;
        }
        bfs(q, 1, matrix, status);

        for (int i = 0; i < numRow; i++) {
            q.emplace(i, numCol - 1);
            status[i][numCol - 1] |= 2;
        }
        for (int j = 0; j + 1 < numCol; j++) {
            q.emplace(numRow - 1, j);
            status[numRow - 1][j] |= 2;
        }
        bfs(q, 2, matrix, status);

        for (int row = 0; row < numRow; row++) 
            for (int col = 0; col < numCol; col++) 
                if (status[row][col] == 3) 
                    answer.push_back({row, col});
        
        return answer;
    }

private:
    const int MOVE_ROW[4] = {-1, 1, 0, 0};
    const int MOVE_COL[4] = {0, 0, -1, 1};
    int numRow, numCol;

    void bfs(queue<pair<int,int>>& q, int bit, vector<vector<int>>& matrix, vector<vector<int>>& status) {
        while (!q.empty()) {
            pair<int,int> pos = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int dr = pos.first + MOVE_ROW[k];
                int dc = pos.second + MOVE_COL[k];
                if (dr < 0 || dr >= numRow || dc < 0 || dc >= numCol)
                    continue;
                if (!(status[dr][dc] & bit) && matrix[dr][dc] >= matrix[pos.first][pos.second]) {
                    q.emplace(dr, dc);
                    status[dr][dc] |= bit;
                }
            }
        }
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<vector<int>>> matrixVec = {
        {
            {1, 2, 2, 3, 5},
            {3, 2, 3, 4, 4},
            {2, 4, 5, 3, 1},
            {6, 7, 1, 4, 5},
            {5, 1, 1, 2, 4}
        }
    };

    /* Output */
    vector<vector<vector<int>>> ret;
    for (vector<vector<int>>& matrix: matrixVec)
        ret.push_back(solution.pacificAtlantic(matrix));

    /* Answer */
    vector<vector<vector<int>>> answer = {
        {{0, 4}, {1, 3}, {1, 4}, {2, 2}, {3, 0}, {3, 1}, {4, 0}}
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