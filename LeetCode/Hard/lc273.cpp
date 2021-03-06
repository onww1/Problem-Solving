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
    string numberToWords(int num) {
        string answer = "";
        int div = 1000000000;
        int unitIdx = 3;
        while (num > 0) {
            int value = num / div % 1000;
            if (value > 0) {
                string threeDigitString = numberToWordsUnderThreeDigits(value);
                append(answer, threeDigitString);
                if (unitIdx > 0)
                    append(answer, macroUnit[unitIdx]);
            }
            num %= div;
            div /= 1000;
            unitIdx--;
        }

        if (answer.length() == 0) 
            append(answer, underTwenty[0]);
        return answer;
    }

private:
    vector<string> macroUnit = {"", "Thousand", "Million", "Billion"};
    vector<string> twoDigits = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> underTwenty = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                                  "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string hundred = "Hundred";

    void append(string& str, string& target) {
        if (str.length() > 0)
            str += " ";
        str += target;
    }

    string numberToWordsUnderThreeDigits(int num) {
        string result = "";
        if (num / 100 > 0) {
            append(result, underTwenty[num / 100]);
            append(result, hundred);
        }

        if (num % 100 < 20) {
            if (num % 100 > 0)
                append(result, underTwenty[num % 100]);
        } else {
            append(result, twoDigits[num % 100 / 10]);
            if (num % 10 > 0) 
                append(result, underTwenty[num % 10]);
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<int> nums = {123, 12345, 1234567, 1234567891};

    /* Output */
    vector<string> ret;
    for (int num: nums)
        ret.push_back(solution.numberToWords(num));

    /* Answer */
    vector<string> answer = {
        "One Hundred Twenty Three",
        "Twelve Thousand Three Hundred Forty Five",
        "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven",
        "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
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