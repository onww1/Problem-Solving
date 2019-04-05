#include <stdio.h>
#include <vector>
using namespace std;

void merge(vector<int> &vec, int i, int mid, int t){
	int a = i, b = mid+1;
	vector<int> tmp;
	while(a <= mid && b <= t){
		if(vec[a] > vec[b]) tmp.push_back(vec[b++]);
		else if(vec[b] > vec[a]) tmp.push_back(vec[a++]);
		else if(vec[a] == vec[b]){
			tmp.push_back(vec[a++]);
			tmp.push_back(vec[b++]);
		}
	}
	if(a <= mid)
		while(a <= mid) tmp.push_back(vec[a++]);
	if(b <= t)
		while(b <= t) tmp.push_back(vec[b++]);
	vec.erase(vec.begin()+i, vec.begin()+t+1);
	vec.insert(vec.begin()+i, tmp.begin(), tmp.end());
	return;
}

void mergesort(vector<int> &vec, int i, int t){
	int mid = (i+t)/2;
	if(i==t) return;
	mergesort(vec, i, mid);
	mergesort(vec, mid+1, t);
	merge(vec, i, mid, t);
	return;
}

int main(void){
	int n, in;
	scanf("%d", &n);
	vector<int> vec;
	for(int i=0; i<n; i++){
		scanf("%d", &in); 
		vec.push_back(in);
	}
	mergesort(vec, 0, n-1);
	for(auto it = begin(vec); it != end(vec); it++)
		printf("%d\n", *it);
	return 0;
}