#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int E, S, M;
	cin >> E >> S >> M;

	int year = E;
	while(true) {
		if( (year-1)%28 + 1 == S ) {
			if( (year-1)%19 + 1 == M ) {
				cout << year << '\n';
				break;
			}
		}
		year += 15;
	}

	return 0;
}