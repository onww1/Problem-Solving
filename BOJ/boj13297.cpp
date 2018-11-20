#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	string input;

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> input;
		cout << input.length() << '\n';
	}

	return 0;
}