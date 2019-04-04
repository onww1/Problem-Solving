#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int w, h, p, q, t;
	cin >> w >> h >> p >> q >> t;

	p += (t%(2*w));
	q += (t%(2*h));

	if(p/w == 1)
		p = (-1)*(p-w)+w;
	else if(p/w == 2)
		p -= 2*w;

	if(q/h == 1)
		q = (-1)*(q-h)+h;
	else if(q/h == 2)
		q -= 2*h;

	cout << p << " " << q << '\n';

	return 0;
}