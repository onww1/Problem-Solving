#include <iostream>
#include <string>
using namespace std;

int game(char p1, char p2) {
	if (p1 == p2) return 0;
	else if ((p1 == 'R' && p2 =='S') || 
			 (p1 == 'S' && p2 =='P') || 
			 (p1 == 'P' && p2 =='R'))
		return 1;
	else return -1;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string p1, p2;
	int w1, w2;

	while (true) {
		cin >> p1 >> p2;
		w1 = w2 = 0;

		if (!p1.compare("E") && !p2.compare("E")) break;

		int len = p1.length();
		for (int i=0; i<len; ++i) {
			int result = game(p1[i], p2[i]);
			if (result > 0) w1++;
			else if (result < 0) w2++;
		}

		cout << "P1: " << w1 << '\n';
		cout << "P2: " << w2 << '\n';
	}
	return 0;
}