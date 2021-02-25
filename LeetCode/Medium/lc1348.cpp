#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <queue>
#include <set>
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
class TweetCounts {
public:
    TweetCounts() {
        records.clear();
    }
    
    void recordTweet(string tweetName, int time) {
        records[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        multiset<int>& times = records[tweetName];
        int delta = freqToDelta(freq);
        endTime++;

        vector<int> results;
        int low = startTime, high;
        while (low < endTime) {
            high = min(endTime, low + delta);
            multiset<int>::iterator left = times.lower_bound(low);
            multiset<int>::iterator right = times.lower_bound(high);
            int count = 0;
            for (multiset<int>::iterator it = left; it != right; it++)
                count++;
            results.push_back(count);
            low = high;
        }

        return results;
    }

private:
    unordered_map<string,multiset<int>> records;

    int freqToDelta(string freq) {
        if (freq == "minute")
            return 60;
        if (freq == "hour")  // 60 * 60
            return 3600; 
        if (freq == "day")   // 60 * 60 * 24
            return 86400; 
        return -1;
    }
};

vector<vector<int>> simulation(vector<string>& commands, vector<vector<string>>& values) {
    TweetCounts* tweetCounts = new TweetCounts();
    vector<vector<int>> answer;
    for (int i = 0; i < commands.size(); i++) {
        if (commands[i] == "recordTweet")
            tweetCounts->recordTweet(values[i][0], stoi(values[i][1]));
        else
            answer.push_back(tweetCounts->getTweetCountsPerFrequency(values[i][0], values[i][1], stoi(values[i][2]), stoi(values[i][3])));
    }
    return answer;
}

int main(int argc, char *argv[]) {
    /* Input */
    vector<vector<string>> commands = {
        {"recordTweet", "recordTweet", "recordTweet", "getTweetCountsPerFrequency", 
         "getTweetCountsPerFrequency", "recordTweet", "getTweetCountsPerFrequency"}
    };
    vector<vector<vector<string>>> values = {
        {{"tweet3", "0"}, {"tweet3", "60"}, {"tweet3", "10"}, {"minute", "tweet3", "0", "59"}, 
         {"minute", "tweet3", "0", "60"}, {"tweet3", "120"}, {"hour", "tweet3", "0", "210"}}
    };

    /* Output */
    vector<vector<vector<int>>> ret;
    for (int i = 0; i < commands.size(); i++)
        ret.push_back(simulation(commands[i], values[i]));

    /* Answer */
    vector<vector<vector<int>>> answer = {
        {{2}, {2, 1}, {4}}
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