#include <algorithm>
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
class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> status;
    unordered_map<string,pair<int,int>> timeCount;

    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        status[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string,int>& prevStatus = status[id];
        string path = prevStatus.first + "#" + stationName;
        pair<int,int>& prevTimeCount = timeCount[path];
        prevTimeCount.first += t - prevStatus.second;
        prevTimeCount.second++;
        status.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string path = startStation + "#" + endStation;
        pair<int,int>& currentTimeCount = timeCount[path];
        return (double)currentTimeCount.first / currentTimeCount.second;
    }
};

vector<double> simulation(vector<string>& command, vector<vector<string>>& value) {
    UndergroundSystem* obj = new UndergroundSystem();
    vector<double> ret;

    for (int i = 0; i < command.size(); i++) {
        if (command[i] == "checkIn") 
            obj->checkIn(stoi(value[i][0]), value[i][1], stoi(value[i][2]));
        else if (command[i] == "checkOut") 
            obj->checkOut(stoi(value[i][0]), value[i][1], stoi(value[i][2]));
        else if (command[i] == "getAverageTime") 
            ret.push_back(obj->getAverageTime(value[i][0], value[i][1]));
    }
    return ret;
}

int main(int argc, char *argv[]) {
    /* Input */
    vector<vector<string>> command = {
        {"checkIn", "checkIn", "checkIn", "checkOut", "checkOut", "checkOut", "getAverageTime", 
         "getAverageTime", "checkIn", "getAverageTime", "checkOut", "getAverageTime"},
        {"checkIn", "checkOut", "getAverageTime", "checkIn", "checkOut", "getAverageTime", 
         "checkIn", "checkOut", "getAverageTime"}
    };
    vector<vector<vector<string>>> value = {
        {
            {"45", "Leyton", "3"}, {"32", "Paradise", "8"}, {"27", "Leyton", "10"}, {"45", "Waterloo", "15"}, {"27", "Waterloo", "20"},
            {"32", "Cambridge", "22"}, {"Paradise", "Cambridge"}, {"Leyton", "Waterloo"}, {"10", "Leyton", "24"}, {"Leyton", "Waterloo"},
            {"10", "Waterloo", "38"}, {"Leyton", "Waterloo"}
        },
        {
            {"10", "Leyton", "3"}, {"10", "Paradise", "8"}, {"Leyton", "Paradise"}, {"5", "Leyton", "10"}, {"5", "Paradise", "16"},
            {"Leyton", "Paradise"}, {"2", "Leyton", "21"}, {"2", "Paradise", "30"}, {"Leyton", "Paradise"}
        }
    };

    /* Output */
    vector<vector<double>> ret;
    for (int i = 0; i < command.size(); i++)
        ret.push_back(simulation(command[i], value[i]));

    /* Answer */
    vector<vector<double>> answer = {
        {14.00000, 11.00000, 11.00000, 12.00000},
        {5.00000, 5.50000, 20.0 / 3}
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