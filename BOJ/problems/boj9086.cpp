#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string str;
	int T;
	cin >> T;
	while (T--) {
		cin >> str;
		cout << str[0] << str[str.length()-1] << '\n';
	}
	return 0;
}