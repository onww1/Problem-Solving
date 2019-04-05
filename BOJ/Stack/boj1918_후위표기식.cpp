#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string infix;
	getline(cin, infix);

	vector<char> op;
	vector<char> postfix;

	int len = infix.length();
	for (int i=0; i<len; i++) {
		if (infix[i] == '(') {
			op.push_back(infix[i]);
		}
		else if (infix[i] == ')') {
			while ( op.back() != '(' ) {
				postfix.push_back(op.back());
				op.pop_back();
			}
			op.pop_back();
		}
		else if (infix[i] == '*' || infix[i] == '/') {
			char top = op.empty() ? 0 : op.back();
			if ( top == '*' || top == '/' ) {
				postfix.push_back(top);
				op.pop_back();
				op.push_back(infix[i]);
			}
			else {
				op.push_back(infix[i]);
			}
		}
		else if (infix[i] == '+' || infix[i] == '-') {
			char top = op.empty() ? 0 : op.back();
			while ( top == '*' || top == '/' ) {
				postfix.push_back(top);
				op.pop_back();
				top = op.back();
			}
			if ( top == '+' || top == '-' ) {
				postfix.push_back(top);
				op.pop_back();
				op.push_back(infix[i]);
			}
			else {
				op.push_back(infix[i]);
			}
		}
		else {
			postfix.push_back(infix[i]);
		}
	}

	while (!op.empty()) {
		postfix.push_back(op.back());
		op.pop_back();
	}

	for (auto it = postfix.begin(); it != postfix.end(); it++) {
		cout << *it;
	}
	cout << '\n';

	return 0;
}