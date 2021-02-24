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
class TimeMap {
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        vector<pair<int,string>>& values = hashMap[key];
        values.emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>>& values = hashMap[key];
        pair<int,string> target = {timestamp, "{"};
        int index = lower_bound(values.begin(), values.end(), target) - values.begin() - 1;
        return index == -1 ? "" : values[index].second;
    }
    
private:
    unordered_map<string, vector<pair<int,string>>> hashMap;
};

vector<string> simulation(vector<string>& cmds, vector<vector<string>>& inputs) {
    TimeMap* timeMap = new TimeMap();
    vector<string> values;
    for (int i = 0; i < cmds.size(); i++) {
        if (cmds[i] == "set")
            timeMap->set(inputs[i][0], inputs[i][1], stoi(inputs[i][2]));
        else 
            values.push_back(timeMap->get(inputs[i][0], stoi(inputs[i][1])));
    }
    return values;
}

int main(int argc, char *argv[]) {
    /* Input */
    vector<vector<string>> cmds = {
        {"set", "get", "get", "set", "get", "get"},
        {"set", "set", "get", "get", "get", "get", "get"}
    };
    vector<vector<vector<string>>> inputs = {
        {
            {"foo", "bar", "1"},
            {"foo", "1"},
            {"foo", "3"},
            {"foo", "bar2", "4"},
            {"foo", "4"},
            {"foo", "5"}
        },
        {
            {"love", "high", "10"},
            {"love", "low", "20"},
            {"love", "5"},
            {"love", "10"},
            {"love", "15"},
            {"love", "20"},
            {"love", "25"}
        }
    };

    /* Output */
    vector<vector<string>> ret;
    for (int i = 0; i < cmds.size(); i++)
        ret.push_back(simulation(cmds[i], inputs[i]));

    /* Answer */
    vector<vector<string>> answer = {
        {"bar", "bar", "bar2", "bar2"},
        {"", "high", "high", "low", "low"}
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