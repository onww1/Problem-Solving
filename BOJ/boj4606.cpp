#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string input;
	while (true) {
		getline(cin, input);
		if (input.compare("#") == 0) break;
		int len = input.length();
		for (int i=0; i<len; i++) {
			char c = input[i];
			if (c == ' ') cout << "%20";
			else if (c == '!') cout << "%21";
			else if (c == '$') cout << "%24";
			else if (c == '%') cout << "%25";
			else if (c == '(') cout << "%28";
			else if (c == ')') cout << "%29";
			else if (c == '*') cout << "%2a";
			else cout << c;
		}
		cout << '\n';
	}
	return 0;
}