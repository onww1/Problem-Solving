#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	string str;
	while (true) {
		vector<char> stack;
		getline(cin, str);
		int len = str.length();

		if (len == 1 && str[0] == '.') break;

		bool isPair = true;
		for (int i=0; i<len; i++) {
			if (str[i] == '(' || str[i] == '[') 
				stack.push_back(str[i]); 
			else if (str[i] == ')') {
				if (stack.empty() || stack.back() == '[') {
					isPair = false;
					break;
				}
				stack.pop_back();
			}
			else if (str[i] == ']') {
				if (stack.empty() || stack.back() == '(') {
					isPair = false;
					break;
				}
				stack.pop_back();
			}
		}

		if (!stack.empty()) isPair = false;

		if (isPair) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}

	return 0;
}