#include <iostream>
#include <string>
using namespace std;

struct list {
	char c;
	list *prev, *next;

	list(): c(0), prev(nullptr), next(nullptr){}
	list(char _c): c(_c), prev(nullptr), next(nullptr){}
};

void printList(list *head) {
	list *ptr = head;
	while (ptr->c != 0) {
		cout << ptr->c;
		ptr = ptr->next;
	}
	cout <<'\n';
}

void addNode(char c, list *cur) {
	list* newNode = new list(c);
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
	delete deletedNode;
}

int main(int argc, char const *argv[])
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string input;
	cin >> input;

	list *head = new list;
	list *tail = new list;
	head->next = tail;
	tail->prev = head;

	int len = input.size();
	for (int i=0; i<len; i++) {
		addNode(input[i], tail);
	}

	int N;
	cin >> N;
	char op, c;
	list *ptr = tail;
	for (int i=0; i<N; i++) {
		cin >> op;
		if (op == 'L') {
			if (ptr->prev->c != 0)
				ptr = ptr->prev;
		}
		else if (op == 'D') {
			if (ptr->next != nullptr)
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

	printList(head->next);
	ptr = tail;
	while (ptr->prev != head)
		deleteNode(ptr);
	delete head;
	delete tail;
	return 0;
}