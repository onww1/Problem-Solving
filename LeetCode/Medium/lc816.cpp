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
    vector<string> ambiguousCoordinates(string s) {
        vector<string> answer;

        s = s.substr(1, (int)s.length() - 2);
        for (int i = 1; i < s.length(); i++) {
            vector<string> left = getValidNumbers(s.substr(0, i));
            vector<string> right = getValidNumbers(s.substr(i));
            for (string& lnum: left)
                for (string& rnum: right)
                    answer.push_back("(" + lnum + ", " + rnum + ")");
        }

        return answer;
    }

private:
    vector<string> getValidNumbers(string numString) {
        vector<string> validNumbers;
        if (isValidNumber(numString, numString.length()))
            validNumbers.push_back(numString);
        for (int i = 1; i < numString.length(); i++)
            if (isValidNumber(numString, i))
                validNumbers.push_back(numString.substr(0, i) + "." + numString.substr(i));
        return validNumbers;
    }

    bool isValidNumber(string& numString, int dlen) {
        if (dlen <= 0 || dlen > numString.length()) 
            return false;

        // Integer
        if (dlen == numString.length()) {
            return numString[0] != '0' || dlen == 1;
        }

        // Decimal
        if (numString[0] == '0' && dlen != 1) 
            return false;
        if (numString.back() == '0')
            return false;
        
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<string> sVec = {
        "(123)",
        "(0123)",
        "(00011)",
        "(100)"
    };

    /* Output */
    vector<vector<string>> ret;
    for (string& s: sVec) {
        vector<string> res = solution.ambiguousCoordinates(s);
        sort(res.begin(), res.end());
        ret.push_back(res);
    }

    /* Answer */
    vector<vector<string>> answer = {
        {"(1, 2.3)", "(1, 23)", "(1.2, 3)", "(12, 3)"},
        {"(0, 1.23)", "(0, 12.3)", "(0, 123)", "(0.1, 2.3)", "(0.1, 23)", "(0.12, 3)"},
        {"(0, 0.011)", "(0.001, 1)"},
        {"(10, 0)"}
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