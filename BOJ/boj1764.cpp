#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N, M;
	vector<string> nh;
	vector<string> ns;

	scanf("%d %d", &N, &M);
	getchar();
	nh.resize(N);
	ns.resize(M);

	string input;
	for(int i=0; i<N; i++){
		getline(cin, input);
		nh[i] = input;
	}
	for(int i=0; i<M; i++){
		getline(cin, input);
		ns[i] = input;
	}

	sort(nh.begin(), nh.end());
	sort(ns.begin(), ns.end());

	
}