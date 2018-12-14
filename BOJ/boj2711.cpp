#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T, I;
	string str;

	cin >> T;
	while (T--) {
		cin >> I;
		cin >> str;
		str.erase(str.begin() + I - 1);
		cout << str << '\n';
	}

	return 0;
}