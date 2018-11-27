#include <iostream>
using namespace std;

void print(double weight) {
	double weightAtMoon = weight * 0.167;
	cout << "Objects weighing " << weight << " on Earth will weigh " << weightAtMoon << " on the moon.\n";
}

int main(int argc, char const *argv[])
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cout << fixed;
	cout.precision(2);

	double w;
	while (1) {
		cin >> w;
		if (w < 0) break;
		print(w);
	}
	return 0;
}