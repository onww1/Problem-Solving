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
class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        size = 1;
        pointer = 0;
    }
    
    void visit(string url) {
        if (pointer + 1 == history.size())
            history.push_back(url);
        else
            history[pointer + 1] = url;
        pointer++;
        size = pointer + 1;
    }
    
    string back(int steps) {
        if (steps > pointer)
            steps = pointer;
        pointer -= steps;
        return history[pointer];
    }
    
    string forward(int steps) {
        if (pointer + steps >= size)
            steps = size - pointer - 1;
        pointer += steps;
        return history[pointer];
    }

private:
    vector<string> history;
    int size;
    int pointer;
};

vector<string> simulation(string& homepage, vector<string>& commands, vector<string>& values) {
    BrowserHistory* browserHistory = new BrowserHistory(homepage);
    vector<string> result;
    for (int i = 0; i < commands.size(); i++) {
        if (commands[i] == "visit") {
            browserHistory->visit(values[i]);
        }
        else if (commands[i] == "back") {
            result.push_back(browserHistory->back(stoi(values[i])));
        }
        else if (commands[i] == "forward") {
            result.push_back(browserHistory->forward(stoi(values[i])));
        }
    }
    return result;
}

int main(int argc, char *argv[]) {
    /* Input */
    vector<string> homepage = {"leetcode.com"};
    vector<vector<string>> commands = {
        {"visit", "visit", "visit", "back", "back", "forward", "visit", "forward", "back", "back"}
    };
    vector<vector<string>> values = {
        {"google.com", "facebook.com", "youtube.com", "1", "1", "1", "linkedin.com", "2", "2", "7"}
    };

    /* Output */
    vector<vector<string>> ret;
    for (int i = 0; i < homepage.size(); i++)
        ret.push_back(simulation(homepage[i], commands[i], values[i]));

    /* Answer */
    vector<vector<string>> answer = {
        {"facebook.com", "google.com", "facebook.com", "linkedin.com", "google.com", "leetcode.com"}
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