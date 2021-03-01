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
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string,vector<pair<int,string>>> hashMap;
        for (int i = 0; i < username.size(); i++) 
            hashMap[username[i]].emplace_back(timestamp[i], website[i]);
        
        unordered_map<string,int> count;
        for (auto it = hashMap.begin(); it != hashMap.end(); it++) {
            vector<pair<int,string>>& visitInfos = it->second;
            sort(visitInfos.begin(), visitInfos.end());

            unordered_set<string> sequenceSet;
            for (int i = 0; i < visitInfos.size(); i++)
                for (int j = i + 1; j < visitInfos.size(); j++)
                    for (int k = j + 1; k < visitInfos.size(); k++)
                        sequenceSet.insert(makeKey(visitInfos, i, j, k));

            for (auto it = sequenceSet.begin(); it != sequenceSet.end(); it++)
                count[*it]++;
        }

        vector<string> answer;
        int maxVisit = 0;
        for (auto it = count.begin(); it != count.end(); it++) {
            if (it->second > maxVisit) {
                answer = splitKey(it->first);
                maxVisit = it->second;
            }
            else if (it->second == maxVisit) {
                vector<string> sequence = splitKey(it->first);
                if (sequence < answer)
                    answer = sequence;
            }
        }

        return answer;
    }

private:
    string makeKey(vector<pair<int,string>>& visitInfos, int firstIndex, int secondIndex, int thirdIndex) {
        return visitInfos[firstIndex].second + "#" + visitInfos[secondIndex].second + "#" + visitInfos[thirdIndex].second;
    }

    vector<string> splitKey(const string& key) {
        vector<string> result;
        int index = 0;
        for (int i = 0; i < key.length(); i++) {
            if (key[i] == '#') {
                result.push_back(key.substr(index, i - index));
                index = i + 1;
            }
        }
        result.push_back(key.substr(index, (int)key.length() - index));
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<string>> username = {
        {"joe", "joe", "joe", "james", "james", "james", "james", "mary", "mary", "mary"}
    };
    vector<vector<int>> timestamp = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    };
    vector<vector<string>> website = {
        {"home", "about", "career", "home", "cart", "maps", "home", "home", "about", "career"}
    };

    /* Output */
    vector<vector<string>> ret;
    for (int i = 0; i < username.size(); i++)
        ret.push_back(solution.mostVisitedPattern(username[i], timestamp[i], website[i]));

    /* Answer */
    vector<vector<string>> answer = {
        {"home", "about", "career"}
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