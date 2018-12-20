#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string str;
	cin >> str;

	bool isHiss = false;
	int len = str.length();
	for (int i=0; i<len-1; ++i) {
		if (str[i] == 's') {
			if (str[i+1] == 's') {
				isHiss = true;
				break;
			} else {
				++i;
			}
		}
	}

	cout << (isHiss?"hiss":"no hiss") << '\n';

	return 0;
}