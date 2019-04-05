#include <cstdio>
#include <algorithm>

using namespace std;

void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

int main(void){
	int sum = 0, h[9];

	for(int i=0; i<9; i++) {
		scanf("%d", &h[i]);
		sum += h[i];
	}

	bool loop = true;
	for(int i=0; i<8 && loop; i++){
		for(int j=i+1; j<9 && loop; j++){
			if(sum - h[i] - h[j] == 100){
				swap(h[j], h[8]);
				swap(h[i], h[7]);
				sort(h, h+7);
				for(int k=0; k<7; k++)
					printf("%d\n", h[k]);
				loop = false;
			}
		}
	}

	return 0;
}