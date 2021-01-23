#include <algorithm>
#include <vector>
#include <cstdio>
#include <cassert>
using namespace std;

/* Solution Class */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int length = 0;
        ListNode* ptr = head;
        while (ptr != nullptr) {
            length++;
            ptr = ptr->next;
        }

        if (!length) return nullptr;
        k %= length;
        if (!k) return head;
        
        k = (length - k);
        ListNode* new_head = head;
        ptr = head;
        while (k > 1) {
            ptr = ptr->next;
            k--;
        }
        new_head = ptr->next;
        ptr->next = nullptr;
        ptr = new_head;

        while (ptr->next != nullptr) 
            ptr = ptr->next;
        ptr->next = head;
        return new_head;
    }
};

ListNode* make_input(vector<int> &vec);
vector<int> parseOutput(ListNode* head);

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> in = {
        {1, 2, 3, 4, 5},
        {0, 1, 2}
    };
    vector<int> k = {2, 4};
    vector<ListNode*> head;
    for (int i = 0; i < in.size(); i++)
        head.push_back(make_input(in[i]));

    /* Output */
    vector<vector<int>> ret;
    for (int i = 0; i < head.size(); i++)
        ret.push_back(parseOutput(solution.rotateRight(head[i], k[i])));

    /* Answer */
    vector<vector<int>> answer = {
        {4, 5, 1, 2, 3},
        {2, 0, 1}
    };

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}

ListNode* make_input(vector<int> &vec) {
    ListNode* head = new ListNode();
    ListNode* ptr = head;
    for (int num: vec) {
        ptr->next = new ListNode(num);
        ptr = ptr->next;
    }
    return head->next;
}

vector<int> parseOutput(ListNode* head) {
    vector<int> ret;
    while (head != nullptr) {
        ret.push_back(head->val);
        head = head->next;
    }
    return ret;
}