#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string str;
	while (true) {
		getline(cin, str);
		if (str.compare("***") == 0)
			break;

		reverse(str.begin(), str.end());
		cout << str << '\n';
	}

	return 0;
}