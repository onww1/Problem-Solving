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
    int superpalindromesInRange(string left, string right) {
        long long leftNum = stol(left);
        long long rightNum = stol(right);
        // return upper_bound(superPalindromes.begin(), superPalindromes.end(), stol(right)) - lower_bound(superPalindromes.begin(), superPalindromes.end(), stol(left));
        
        long long lower = 1, upper = 1000000000;

        long long lo = 1, hi = 1000000000;
        while (lo <= hi) {
            long long mid = (lo + hi) >> 1;
            if (mid * mid >= leftNum)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        lower = lo;

        lo = 1, hi = 1000000000;
        while (lo <= hi) {
            long long mid = (lo + hi) >> 1;
            if (mid * mid <= rightNum) 
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        upper = hi;

        int minLen = getLen(lower);
        int maxLen = getLen(upper);
        vector<string> pNums = getAllPalindromeNumber(minLen, maxLen);
        
        int answer = 0;
        for (string& pn: pNums) {
            long long num = stol(pn);
            long long numnum = num * num;
            if (lower <= num && num <= upper && isPalindrome(numnum)) 
                answer++; 
        }

        return answer;
    }

private:
    vector<long long> superPalindromes = {1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004, 100000020000001, 100220141022001, 102012040210201, 102234363432201, 121000242000121, 121242363242121, 123212464212321, 123456787654321, 400000080000004, 10000000200000001, 10002000300020001, 10004000600040001, 10020210401202001, 10022212521222001, 10024214841242001, 10201020402010201, 10203040504030201, 10205060806050201, 10221432623412201, 10223454745432201, 12100002420000121, 12102202520220121, 12104402820440121, 12122232623222121, 12124434743442121, 12321024642012321, 12323244744232321, 12343456865434321, 12345678987654321, 40000000800000004, 40004000900040004};

    int getLen(long long num) {
        int len = 0;
        while (num) {
            len++;
            num /= 10;
        }
        return len;
    }

    void getPalindromeNumbers(int len, string cur, vector<string>& numbers) {
        if (cur.length() == len) {
            if (cur[0] != '0' || len == 1)
                numbers.push_back(cur);
            return;
        }

        bool flag = (cur.length() % 2 == len % 2);
        for (char c = '0'; c <= '9'; c++) {
            if (flag) 
                getPalindromeNumbers(len, c + cur + c, numbers);
            else
                getPalindromeNumbers(len, cur + c, numbers);
        }
    }

    vector<string> getAllPalindromeNumber(int minLen, int maxLen) {
        vector<string> numbers;
        for (int len = minLen; len <= maxLen; len++) 
            getPalindromeNumbers(len, "", numbers);
        return numbers;
    }

    bool isPalindrome(long long num) {
        vector<long long> digits;
        while (num) {
            digits.push_back(num % 10);
            num /= 10;
        }
        int n = digits.size();
        for (int i = 0; 2 * i < n - 1; i++) 
            if (digits[i] != digits[n - 1 - i])
                return false;
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<string> left = {"4", "1"};
    vector<string> right = {"1000", "2"};

    /* Output */
    vector<int> ret;
    for (int i = 0; i < left.size(); i++)
        ret.push_back(solution.superpalindromesInRange(left[i], right[i]));        

    /* Answer */
    vector<int> answer = {4, 1};

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