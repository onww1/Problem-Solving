#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <unordered_map>
using namespace std;

/* Solution Class */
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        unordered_map<Node*,int> idx;
        Node* ptr = head;
        int cnt = 0;
        while (ptr) {
            idx[ptr] = cnt++;
            ptr = ptr->next;
        }
        
        vector<Node*> nodes;
        vector<int> random_idx;
        Node* copied_head = new Node(0);
        ptr = copied_head;
        while (head) {
            ptr->next = new Node(head->val);
            ptr = ptr->next;
            if (head->random) random_idx.push_back(idx[head->random]);
            else random_idx.push_back(-1);
            nodes.push_back(ptr);
            head = head->next;
        }
        for (int i = 0; i < random_idx.size(); i++) {
            if (random_idx[i] != -1) {
                nodes[i]->random = nodes[random_idx[i]];
            }
        }
        return copied_head->next;
    }
};

Node* make_list(vector<vector<int>>& nodes);
bool is_match(Node* anode, Node* bnode);

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<vector<int>>> nodes = {
        {{7, -1}, {13, 0}, {11, 4}, {10, 2}, {1, 0}},
        {{1, 1}, {2, 1}},
        {{3, -1}, {3, 0}, {3, -1}},
        {}
    };

    vector<Node*> head;
    for (int i = 0; i < nodes.size(); i++)
        head.push_back(make_list(nodes[i]));

    /* Output */
    vector<Node*> ret;
    for (int i = 0; i < head.size(); i++)
        ret.push_back(solution.copyRandomList(head[i]));

    /* Answer */
    vector<Node*> answer;
    for (int i = 0; i < nodes.size(); i++)
        answer.push_back(make_list(nodes[i]));

    /* Check */
    bool match = true;
    for (int i = 0; i < ret.size(); i++)
        match &= is_match(ret[i], answer[i]);

    assert(match);

    puts("PASS!");
    return 0;
}

Node* make_list(vector<vector<int>>& nodes) {
    if (nodes.empty()) return NULL;
    Node* head = new Node(nodes[0][0]);
    Node* ptr = head;
    vector<Node*> node_vector = {head};
    for (int i = 1; i < nodes.size(); i++) {
        ptr->next = new Node(nodes[i][0]);
        ptr = ptr->next;
        node_vector.push_back(ptr);
    }
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i][1] != -1) {
            node_vector[i]->random = node_vector[nodes[i][1]];
        }
    }
    return head;
}

bool is_match(Node* anode, Node* bnode) {
    while (true) {
        if (!anode && !bnode) return true;
        if (!anode || !bnode) return false;
        if (anode == bnode) return false;
        if (anode->val != bnode->val) return false;
        if (anode->random && !bnode->random) return false;
        if (!anode->random && bnode->random) return false;
        if (anode->random && bnode->random && anode->random->val != bnode->random->val) return false;
        anode = anode->next;
        bnode = bnode->next;
    }
    return false;
}