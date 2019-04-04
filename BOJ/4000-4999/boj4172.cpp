#include <cstdio>
#include <cmath>

int x[1000001] = {1};

int getX(int i){
	if(x[i] > 0) return x[i];
	return x[i] = ( getX((int)std::floor((double)i-std::sqrt((double)i)))
				  + getX((int)std::floor(std::log((double)i)))
				  + getX((int)std::floor((double)i * std::sin((double)i) * std::sin((double)i)))
				  ) % 1000000;
}

int main(void){
	int in;
	while(1){
		scanf("%d", &in);
		if(in == -1) break;
		printf("%d\n", getX(in));
	}
	return 0;
}