#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};

ListNode* make_list(vector<int>& nodes, int pos);

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> nodes = {
        {3, 2, 0, -4},
        {1, 2},
        {1}
    };
    vector<int> pos = {1, 0, -1};

    vector<ListNode*> head;
    for (int i = 0; i < nodes.size(); i++)
        head.push_back(make_list(nodes[i], pos[i]));

    /* Output */
    vector<bool> ret;
    for (int i = 0; i < head.size(); i++)
        ret.push_back(solution.hasCycle(head[i]));

    /* Answer */
    vector<bool> answer = {true, true, false};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}

ListNode* make_list(vector<int>& nodes, int pos) {
    if (nodes.empty()) return NULL;
    ListNode* head = new ListNode(0);
    ListNode* ptr = head;
    ListNode* keep = NULL;
    
    for (int i = 0; i < nodes.size(); i++) {
        ptr->next = new ListNode(nodes[i]);
        ptr = ptr->next;
        if (i == pos) keep = ptr;
    }

    ptr->next = keep;
    return head->next;
}