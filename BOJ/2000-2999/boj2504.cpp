#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

int main(void){
	stack<char> par;
	stack<int> tmp;
	char in[31];
	int a, b;
	scanf("%s", in);
	int i, len = strlen(in);
	for(i=0; i<len; i++){
		if(in[i] == '('){
			par.push(in[i]);
			tmp.push(2);
		} else if(in[i] == '['){
			par.push(in[i]);
			tmp.push(3);
		} else if(in[i] == ')'){
			if(par.empty() || par.top() != '('){printf("0\n"); return 0;}
			par.pop();
			b = tmp.top();
			tmp.pop();
			if(b != 2) b = 2 * (b-2);
			if(tmp.empty()) tmp.push(b);
			else{
				a = tmp.top();
				tmp.pop();
				tmp.push(a+b);
			}
		} else if(in[i] == ']'){
			if(par.empty() || par.top() != '['){printf("0\n"); return 0;}
			par.pop();
			b = tmp.top();
			tmp.pop();
			if(b != 3) b = 3 * (b-3);
			if(tmp.empty()) tmp.push(b);
			else{
				a = tmp.top();
				tmp.pop();
				tmp.push(a+b);
			}
		}
	}
	a = 0;
	while(!tmp.empty()){a+=tmp.top(); tmp.pop();}
	if(!par.empty()) printf("0\n");
	else printf("%d\n", a);
	return 0;
}
