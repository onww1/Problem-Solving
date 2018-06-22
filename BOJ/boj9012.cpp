#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

int main(void){
	int n;
	char in[51], i, len;
	scanf("%d", &n);
	while(n--){
		scanf("%s", in);
		len = strlen(in);
		stack<char> stk;
		for(i=0; i<len; i++){
			if(in[i] == '(') stk.push(in[i]);
			else if(in[i] == ')'){
				if(stk.empty() == true) break;
				else stk.pop();
			}
		}
		printf("%s\n", (stk.empty())?((i==len)?"YES":"NO"):"NO");
	}
	return 0;
}