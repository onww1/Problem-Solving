#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int x[3], y[3];
	for(int i=0; i<3; i++){
		cin >> x[i] >> y[i];
	}

	int dx1 = x[1] - x[0];
	int dx2 = x[2] - x[0];
	int dy1 = y[1] - y[0];
	int dy2 = y[2] - y[0];

	int S = dx1 * dy2 - dy1 * dx2;

	if(S < 0) cout << "-1" << '\n';
	else if(S > 0) cout << "1" << '\n';
	else cout << "0" << '\n';

	return 0;
}