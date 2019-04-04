#include <cstdio>
#include <vector>
#include <cstring>

int main(void){
	char input[100001];
	scanf("%s", input);

	std::vector<int> laser;
	int ans = 0;

	int len = strlen(input);
	int cnt = 0;
	for(int i=0; i<len; i++){
		if(input[i] == '('){
			if(input[i+1] == ')'){
				cnt++;
				i++;
			} else {
				laser.push_back(cnt);
				cnt = 0;
			}
		} else if(input[i] == ')'){
			ans += (cnt + 1);
			if(!laser.empty()){
				cnt += laser.back();
				laser.pop_back();
			} else {
				cnt = 0;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

