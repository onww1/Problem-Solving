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
class Item {

private:
    char type;
    string name;
}

class FileSystem {
public:
    FileSystem() {
        
    }
    
    vector<string> ls(string path) {
        
    }
    
    void mkdir(string path) {
        
    }
    
    void addContentToFile(string filePath, string content) {
        
    }
    
    string readContentFromFile(string filePath) {
        
    }
};

vector<vector<string>> simulation(vector<string>& commands, vector<vector<string>>& values) {
    FileSystem* fs = new FileSystem();
    vector<vector<string>> result;
    for (int i = 0; i < commands.size(); i++) {
        if (commands[i] == "ls") 
            result.push_back(fs->ls(values[i][0]));
        else if (commands[i] == "mkdir") 
            fs->mkdir(values[i][0]);
        else if (commands[i] == "addContentToFile") 
            fs->addContentToFile(values[i][0], values[i][1]);
        else 
            result.push_back({fs->readContentFromFile(values[i][0])});
    }
    return result;
}

int main(int argc, char *argv[]) {
    /* Input */
    vector<string> commands = {"ls", "mkdir", "addContentToFile", "ls", "readContentFromFile"};
    vector<vector<string>> values = {{"/"}, {"/a/b/c"}, {"/a/b/c/d", "hello"}, {"/"}, {"/a/b/c/d"}};

    /* Output */
    vector<vector<string>> ret = simulation(commands, values);

    /* Answer */
    vector<vector<string>> answer = {{}, {"a"}, {"hello"}};

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
