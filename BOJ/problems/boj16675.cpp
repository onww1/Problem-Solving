#include <iostream>
using namespace std;

int game(char a, char b) {
	if (a == b) return 0;
	else if ((a == 'R' && b == 'S') ||
			 (a == 'S' && b == 'P') ||
			 (a == 'P' && b == 'R')) return 1;
	else return -1;
}

int main(int argc, char const *argv[])
{
	char ml, mr, tl, tr;
	cin >> ml >> mr >> tl >> tr;

	if ((game(ml, tl) > 0 && game(ml, tr) > 0) ||
		(game(mr, tl) > 0 && game(mr, tr) > 0)) cout << "MS" << '\n';
	else if ((game(ml, tl) < 0 && game(mr, tl) < 0) ||
			 (game(ml, tr) < 0 && game(mr, tr) < 0)) cout << "TK" << '\n';
	else cout << '?' << '\n';

	return 0;
}