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
    vector<vector<int>> kClosestV1(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), [](vector<int>& pointA, vector<int>& pointB) {
            int squareDistanceA = pointA[0] * pointA[0] + pointA[1] * pointA[1];
            int squareDistanceB = pointB[0] * pointB[0] + pointB[1] * pointB[1];
            return squareDistanceA < squareDistanceB;
        });
        while (points.size() > K)
            points.pop_back();
        return points;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        mySort(0, (int)points.size() - 1, K, points);
        while (points.size() > K)
            points.pop_back();
        return points;
    }

private:
    void mySort(int left, int right, int K, vector<vector<int>>& points) {
        if (left >= right)
            return;
        int pt = rand() % (right - left + 1) + left;
        swap(points[left], points[pt]);

        int mid = partition(left, right, points);
        int leftLength = mid - left + 1;
        if (K < leftLength)
            mySort(left, mid - 1, K, points);
        else if (K > leftLength) 
            mySort(mid + 1, right, K - leftLength, points);
    }

    int partition(int left, int right, vector<vector<int>>& points) {
        int org = left;
        int pivot = distance(points[left]);
        left++;

        while (true) {
            while (left < right && distance(points[left]) < pivot)
                left++;
            while (left <= right && distance(points[right]) >= pivot)
                right--;
            if (left >= right) 
                break;
            swap(points[left], points[right]);
        }

        swap(points[right], points[org]);
        return right;
    }

    int distance(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<vector<int>>> points ={
        {{1, 3}, {-2, 2}},
        {{3, 3}, {5, -1}, {-2, 4}}
    };
    vector<int> K = {1, 2};

    /* Output */
    vector<vector<vector<int>>> ret;
    for (int i = 0; i < points.size(); i++)
        ret.push_back(solution.kClosest(points[i], K[i]));

    /* Answer */
    vector<vector<vector<int>>> answer = {
        {{-2, 2}},
        {{3, 3}, {-2, 4}}
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