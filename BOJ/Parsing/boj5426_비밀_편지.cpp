#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	string input;
	while (tc--) {
		cin >> input;
		int len = input.length();
		int sqrt = 1;
		for (; sqrt * sqrt < len; sqrt++);
		string result;

		for (int j=sqrt-1; j >= 0; j--) {
			for (int i=0; i<sqrt; i++) {
				result += input[sqrt * i + j];
			}
		}
		cout << result << '\n';
	}
	return 0;
}