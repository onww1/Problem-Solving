#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int w[10];
	int k[10];
	int sumw = 0, sumk = 0;

	for(int i=0; i<10; i++)
		cin >> w[i];
	for(int i=0; i<10; i++)
		cin >> k[i];

	sort(w, w+10);
	sort(k, k+10);

	sumw = w[7] + w[8] + w[9];
	sumk = k[7] + k[8] + k[9];

	cout << sumw << " " << sumk << '\n';
	return 0;
}