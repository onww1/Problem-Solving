#include <iostream>
#include <string>
using namespace std;

int judge(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
		c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return 1;
	else if (c == 'y' || c == 'Y') return 2;
	else return 0;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string str;
	int N;

	cin >> N;
	for (int i=1; i<=N; ++i) {
		cin >> str;
		int now = judge(str[str.length()-1]);
		if (now == 0) cout << "Case #" << i << ": " << str << " is ruled by a king." << '\n';
		else if (now == 1) cout << "Case #" << i << ": " << str << " is ruled by a queen." << '\n';
		else if (now == 2) cout << "Case #" << i << ": " << str << " is ruled by nobody." << '\n';
	}
	return 0;
}