#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int a, b;
	while (1) {
		cin >> a >> b;
		if (!a && !b) break;
		if (a<b && b%a==0) cout << "factor" << '\n';
		else if (a>b && a%b==0) cout << "multiple" << '\n';
		else cout << "neither" << '\n';
	}
	return 0;
}