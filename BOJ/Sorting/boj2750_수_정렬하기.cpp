#include <iostream>
#include <vector>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

int main(void){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;
	std::cin >> n;

	std::vector<int> vec(n);
	for(int i=0; i<n; i++) std::cin >> vec[i];

	for(int i=n-1; i>=0; i--){
		for(int j=1; j<=i; j++){
			if(vec[j]<vec[j-1]) 
				swap(&vec[j], &vec[j-1]);
		}
	}

	for(int i=0; i<n; i++)
		std::cout << vec[i] << '\n';

	return 0;	
}