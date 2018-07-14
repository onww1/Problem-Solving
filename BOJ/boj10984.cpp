#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;

	int n;
	int c[10];
	double g[10];

	int total;
	double gpa;

	cout << fixed;
	cout.precision(1);

	while(t--)
	{
		total = 0;
		gpa = 0.0;

		cin >> n;
		for(int i=0; i<n; i++)
		{
			cin >> c[i] >> g[i];
			total += c[i];
			gpa += (g[i] * (double)c[i]);
		}
		gpa /= (double)total;

		cout << total << " " << gpa << '\n';
	}

	return 0;
}