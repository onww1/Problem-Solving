#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;

int main(void){
	stack<int> numstk;
	vector<char> result;
	int num=0;
	int n, in, tmp;

	scanf("%d", &n);
	while(n--){
		scanf("%d", &in);
		if(in >= num){
			while(in > num){
				numstk.push(++num);
				result.push_back('+');
			}
			numstk.pop();
			result.push_back('-');
		} else if(in < num){
			tmp = numstk.top();
			numstk.pop();
			if(tmp != in){
				printf("NO\n");
				return 0;
			} else result.push_back('-');
		}
	}

	for(auto it=begin(result); it != end(result); it++)
		printf("%c\n", *it);
	return 0;
}