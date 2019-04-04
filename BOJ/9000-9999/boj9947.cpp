#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string name1, name2;
	int n;
	char t1, t2;

	while (true) {
		cin >> name1 >> name2;
		if (name1.compare("#") == 0 && name2.compare("#") == 0)
			break;

		cin >> n;
		int p1 = 0, p2 = 0;
		for (int i=0; i<n; i++) {
			cin >> t1 >> t2;
			if (t1 == t2) p1++;
			else p2++;
		}
		cout << name1 << ' ' << p1 << ' ' << name2 << ' ' << p2 << '\n';
	}
	return 0;
}