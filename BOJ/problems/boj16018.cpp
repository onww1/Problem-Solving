#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	string y, t;
	cin >> n;
	cin >> y >> t;
	int cnt = 0;
	for (int i=0; i<n; i++) {
		if (y[i] == 'C' && y[i] == t[i]) cnt++;
	}
	cout << cnt << '\n';
	return 0;
}