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
    int lenLongestFibSubseqV1(vector<int>& arr) {
        unordered_set<int> hashSet(arr.begin(), arr.end());
        int answer = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                int a = arr[i], b = arr[j], cnt = 2;
                while (hashSet.count(a + b) > 0) {
                    int c = a + b;
                    a = b; b = c;
                    cnt++;
                }
                if (cnt >= 3)
                    answer = max(answer, cnt);
            }
        }
        return answer;
    }

    int lenLongestFibSubseqV2(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> index;
        for (int i = 0; i < n; i++)
            index[arr[i]] = i;

        int answer = 0;
        unordered_map<int,int> dp;
        for (int k = 2; k < n; k++) {
            for (int j = 1; j < k; j++) {
                if (arr[k] - arr[j] < arr[j] && index.count(arr[k] - arr[j])) {
                    int i = index[arr[k] - arr[j]];
                    dp[j * n + k] = dp[i * n + j] + 1;
                    answer = max(answer, dp[j * n + k] + 2);
                }
            }
        }

        return answer;
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> index;
        for (int i = 0; i < n; i++)
            index[arr[i]] = i;

        int answer = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int k = 2; k < n; k++) {
            for (int j = 1; j < k; j++) {
                if (arr[k] - arr[j] < arr[j] && index.count(arr[k] - arr[j])) {
                    int i = index[arr[k] - arr[j]];
                    dp[j][k] = dp[i][j] + 1;
                    answer = max(answer, dp[j][k] + 2);
                }
            }
        }

        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> arr = {
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 3, 7, 11, 12, 14, 18}
    };

    /* Output */
    vector<int> ret;
    for (int i = 0; i < arr.size(); i++)
        ret.push_back(solution.lenLongestFibSubseq(arr[i]));

    /* Answer */
    vector<int> answer = {5, 3};
    
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