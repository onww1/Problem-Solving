#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string str;
	cin >> str;

	int cnt = 1, len = str.length();
	for (int i=1; i<len-1; ++i) {
		if (str[i] == ',') cnt++;
	}
	cout << cnt << '\n';
	return 0;
}