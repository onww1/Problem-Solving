#include <cstdio>
#include <cstring>
#include <deque>

std::deque<char> gear[5];

void rotate(int prev, int cur, int direction){
	int left = 0, right = 0, nextDirection = (direction==1?-1:1);
	if(cur > 1 && cur - 1 != prev){
		if(gear[cur][6] != gear[cur-1][2]) left = 1;
	}
	if(cur < 4 && cur + 1 != prev){
		if(gear[cur][2] != gear[cur+1][6]) right = 1;
	}

	if(direction == 1){
		int tmp = gear[cur].back();
		gear[cur].pop_back();
		gear[cur].push_front(tmp);
	} else if(direction == -1){
		int tmp = gear[cur].front();
		gear[cur].pop_front();
		gear[cur].push_back(tmp);
	}

	if(left) rotate(cur, cur-1, nextDirection);
	if(right) rotate(cur, cur+1, nextDirection);
}

int main(void){
	char input[9];
	int t, n, d;
	for(int i=1; i<=4; i++){
		scanf("%s", input);
		gear[i].assign(input, input+8);
	}
	
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &d);
		rotate(-1, n, d);
	}

	int val = 1, ans = 0;
	for(int i=1; i<=4; i++){
		ans += ( gear[i][0] - '0' ) * val;
		val <<= 1;
	}

	printf("%d\n", ans);
	return 0;
}