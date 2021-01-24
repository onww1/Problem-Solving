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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* head = new ListNode();
        ListNode* ptr = head;
        while (a != nullptr && b != nullptr) {
            if (a->val < b->val) {
                ptr->next = new ListNode(a->val);
                a = a->next;
            }
            else {
                ptr->next = new ListNode(b->val);
                b = b->next;
            }
            ptr = ptr->next;
        }
        while (a != nullptr) {
            ptr->next = new ListNode(a->val);
            a = a->next;
            ptr = ptr->next;
        }
        while (b != nullptr) {
            ptr->next = new ListNode(b->val);
            b = b->next;
            ptr = ptr->next;
        }
        return head->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (!n) return nullptr;
        for (int d = 1; d < n; d <<= 1) {
            for (int i = 0; i + d < n; i += 2 * d) {
                lists[i] = merge(lists[i], lists[i + d]);
            }
        }
        return lists[0];
    }
};

vector<ListNode*> make_lists(vector<vector<int>> values);
ListNode* make_list(vector<int> values);
bool compareLists(ListNode* a, ListNode* b);

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<vector<int>>> values = {
        {
            {1, 4, 5},
            {1, 3, 4},
            {2, 6}
        },
        {},
        {
            {}
        }
    };
    vector<vector<ListNode*>> lists;
    for (int i = 0; i < values.size(); i++)
        lists.push_back(make_lists(values[i]));

    /* Output */
    vector<ListNode*> ret;
    for (int i = 0; i < lists.size(); i++)
        ret.push_back(solution.mergeKLists(lists[i]));

    /* Answer */
    vector<vector<int>> ans = {
        {1, 1, 2, 3, 4, 4, 5, 6},
        {},
        {}
    };
    vector<ListNode*> answer = make_lists(ans);

    /* Check */
    bool result = true;
    for (int i = 0; i < ret.size(); i++)
        result &= compareLists(ret[i], answer[i]);
    assert(result);

    puts("PASS!");
    return 0;
}

vector<ListNode*> make_lists(vector<vector<int>> values) {
    vector<ListNode*> ret;
    for (int i = 0; i < values.size(); i++) 
        ret.push_back(make_list(values[i]));
    return ret;
}

ListNode* make_list(vector<int> values) {
    ListNode* head = new ListNode();
    ListNode* ptr = head;
    for (int i = 0; i < values.size(); i++) {
        ptr->next = new ListNode(values[i]);
        ptr = ptr->next;
    }
    return head->next;
}

bool compareLists(ListNode* a, ListNode* b) {
    while (a != nullptr && b != nullptr) {
        if (a->val != b->val) return false;
        a = a->next;
        b = b->next;
    }
    return a == nullptr && b == nullptr;
}