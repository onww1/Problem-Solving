// #include <cstdio>
// #include <cmath>
// using namespace std;

// int main(int argc, char *argv[]) {
// 	int t, n, c, ss, i;
// 	double g, s;
// 	scanf("%d", &t);
// 	while (t--) {
// 		scanf("%d", &n);
// 		ss = 0, s = 0.0;
// 		for (i = 0; i < n; ++i) {
// 			scanf("%d %lf", &c, &g);
// 			ss += c;
// 			s += (g * (double)c);
// 		}
// 		printf("%d %.1lf\n", ss, round(s / ss * 10) / 10.0);
// 	}
// 	return 0;
// }

#include <iostream>
#include <cmath>
using namespace std;
int t,n;
double c[10] , g[10];
int main(){
    cin >> t;
    while(t--){
        double csum=0.0, gsum=0.0;
        cin >> n;
        for(int i=0; i<n; ++i){
            cin >> c[i]  >> g[i];
            csum += c[i];
            gsum += c[i] * g[i];
        }
        cout << fixed;
        cout.precision(1);
        if(gsum/csum == 0) 
            cout << csum << " 0.0" << '\n';
        else cout << csum << " "<< round(gsum / csum * 10) / 10 << '\n';
    }
    return 0;
}