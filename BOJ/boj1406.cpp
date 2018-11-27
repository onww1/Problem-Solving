#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct list {
	char c;
	list *prev, *next;
};

void printList(list *head) {
	list *ptr = head;
	while (ptr->next->c != 0) {
		ptr = ptr->next;
		cout << ptr->c;
	}
	cout <<'\n';
}

void addNode(char c, list *cur) {
	list* newNode = (list*)malloc(sizeof(list));
	newNode->c = c;
	newNode->next = cur;
	newNode->prev = cur->prev;
	cur->prev->next = newNode;
	cur->prev = newNode;
}

void deleteNode(list *cur) {
	if (cur->prev->c == 0) return;
	list *deletedNode = cur->prev;
	cur->prev->prev->next = cur;
	cur->prev = cur->prev->prev;
	free(deletedNode);
}

int main(int argc, char const *argv[])
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string input;
	cin >> input;

	list *head = (list*)malloc(sizeof(list));
	list *tail = (list*)malloc(sizeof(list));
	head->next = tail;
	tail->prev = head;

	list *ptr = tail;

	int len = input.length();
	for (int i=0; i<len; i++) {
		addNode(input[i], ptr);
	}

	fflush(stdout);
	int N;
	cin >> N;
	char op, c;
	for (int i=0; i<N; i++) {
		cin >> op;
		if (op == 'L') {
			if (ptr->prev->c != 0)
				ptr = ptr->prev;
		}
		else if (op == 'D') {
			if (ptr->next != NULL)
				ptr = ptr->next;
		}
		else if (op == 'B') {
			deleteNode(ptr);
		}
		else if (op == 'P') {
			cin >> c;
			addNode(c, ptr);
		}
	}

	printList(head);
	ptr = tail;
	while (ptr->prev != head)
		deleteNode(ptr);
	free(head);
	free(tail);
	return 0;
}