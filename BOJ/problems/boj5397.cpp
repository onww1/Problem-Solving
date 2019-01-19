#include <cstdio>
#include <cstring>
using namespace std;

struct Node {
  char v;
  Node *l, *r;

  Node():v(0),l(0),r(0){}
  Node(char c):v(c),l(0),r(0){}
};

Node *head, *tail;

void insert(Node *ptr, char c) {
  Node *newNode = new Node(c);
  newNode->l = ptr->l;
  newNode->r = ptr;
  ptr->l->r = newNode;
  ptr->l = newNode;
}

void remove(Node *ptr) {
  Node *deletedNode = ptr->l;
  if (deletedNode == head) return;
  deletedNode->l->r = ptr;
  ptr->l = deletedNode->l;
  delete deletedNode;
}

void print() {
  char res[1000050];
  int idx = 0;
  Node *ptr = head->r;
  while (ptr->v != 0) {
    res[idx++] = ptr->v;
    ptr = ptr->r;
  }
  res[idx] = 0;
  printf("%s\n", res);
}

void removeAll() {
  Node *ptr = head->r;
  while (tail->l != head) remove(tail);
  delete(head);
  delete(tail);
}

char in[1000050];
int main(int argc, char *argv[]) {
  int t, n, i;
  scanf("%d", &t);
  while (t--) {
    scanf(" %s", in);
    n = strlen(in);

    head = new Node;
    Node *cur = tail = new Node;
    head->r = tail;
    tail->l = head;

    for (i = 0; i < n; ++i) {
      if (in[i] == '<') {
        if (cur->l == head) continue;
        cur = cur->l;
      } else if (in[i] == '>') {
        if (cur == tail) continue;
        cur = cur->r;
      } else if (in[i] == '-') {
        if (cur->l == head) continue;
        remove(cur);
      } else {
        insert(cur, in[i]);
      }
    }

    print();
    removeAll();
  }
  return 0;
}