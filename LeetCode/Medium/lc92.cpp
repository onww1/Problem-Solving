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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prevLeft = NULL;
        ListNode* nextRight = NULL;
        ListNode* leftNode = NULL;
        ListNode* rightNode = NULL;
        ListNode* ptr = head;

        int order = 1;
        while (ptr) {
            if (order + 1 == left)
                prevLeft = ptr;
            if (order - 1 == right)
                nextRight = ptr;
            if (order == left)
                leftNode = ptr;
            if (order == right)
                rightNode = ptr;

            order++;
            ptr = ptr->next;
        }

        pair<ListNode*,ListNode*> reversedList = reverseList(leftNode, rightNode);
        if (prevLeft)
            prevLeft->next = reversedList.first;
        else
            head = reversedList.first;
        
        if (nextRight)
            reversedList.second->next = nextRight;

        return head;
    }

private:
    pair<ListNode*,ListNode*> reverseList(ListNode* start, ListNode* end) {
        ListNode* ptr = start;
        ListNode* prevNode = NULL;

        while (true) {
            ListNode* nextNode = ptr->next;
            ptr->next = prevNode;
            prevNode = ptr;

            if (ptr == end)
                break;

            ptr = nextNode;
        }

        return {end, start};
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> nodes = {
        {1, 2, 3, 4, 5},
        {5}
    };
    vector<int> left = {2, 1};
    vector<int> right = {4, 1};

    vector<ListNode*> head;
    for (int i = 0; i < nodes.size(); i++)
        head.push_back(makeList(nodes[i]));

    /* Output */
    vector<ListNode*> ret;
    for (int i = 0; i < head.size(); i++)
        ret.push_back(solution.reverseBetween(head[i], left[i], right[i]));

    /* Answer */
    vector<vector<int>> anodes = {
        {1, 4, 3, 2, 5},
        {5}
    };

    vector<ListNode*> answer;
    for (int i = 0; i < anodes.size(); i++)
        answer.push_back(makeList(anodes[i]));

    /* Check */
    bool match = true;
    for (int i = 0; i < ret.size(); i++)
        match &= matchList(ret[i], answer[i]);
    assert(match);

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