// #include <cstdio>
// using namespace std;

// struct Node {
//   int val;
//   Node *left, *right;

//   Node(int val) : val(val), left(0), right(0){}
// };

// void postorder(Node *node);
// void addNode(Node *node, int val);

// int main(int argc, char *argv[]) {
//   Node *root = NULL;
//   int val;

//   while (~scanf("%d", &val)) {
//     if (root == NULL) root = new Node(val);
//     else addNode(root, val);
//   }

//   postorder(root);
//   return 0;
// }

// void postorder(Node *node) {
//   if (node == 0) return;

//   postorder(node->left);
//   postorder(node->right);
//   printf("%d\n", node->val);
// }

// void addNode(Node *node, int val) {
//   if (node->val > val) {
//     if (node->left == 0) node->left = new Node(val);
//     else addNode(node->left, val);
//   } else if (node->val < val) {
//     if (node->right == 0) node->right = new Node(val);
//     else addNode(node->right, val);
//   }
// }

#include <cstdio>
using namespace std;

int a[10050], n;
void solve(int s, int e) {
  if (s >= e) return;
  int l = s + 1, r = e;
  while (l < r) {
    int m = (l + r) / 2;
    if (a[m] > a[s]) r = m;
    else l = m + 1;
  }
  solve(s + 1, r);
  solve(r, e);
  printf("%d\n", a[s]);
}

int main(int argc, char *argv[]) {
  while (~scanf("%d", &a[n++]));
  solve(0, n-1);
  return 0;  
}