#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T, N;
	double ri, ci, rma, cma, rmi, cmi;

	cout << fixed;
	cout.precision(9);

	cin >> T;
	for (int tc=1; tc<=T; ++tc) {
		cin >> N;
		cma = rma = -1001.0;
		cmi = rmi = 1001;
		for (int i=0; i<N; ++i) {
			cin >> ri >> ci;
			rma = rma < ri ? ri : rma;
			cma = cma < ci ? ci : cma;
			rmi = rmi < ri ? rmi : ri;
			cmi = cmi < ci ? cmi : ci;
		}

		double area = (rma - rmi) * (cma - cmi);
		double peri = (rma - rmi + cma - cmi) * 2;
		cout << "Case " << tc << ": Area " << area << ", Perimeter " << peri << '\n'; 
	}
	return 0;
}