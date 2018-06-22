#include <cstdio>
#include <cstring>
#include <deque>
#include <list>

bool check(int elem, std::deque<int> dq);

int main(void){

	// define
	int n, m, in, num, cnt=0;
	std::deque<int> dq;
	std::list<int> dst;

	// initialize
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) dq.push_back(i);
	for(int i=0; i<m; i++){
		scanf("%d", &in);
		dst.push_back(in);
	}

	// process
	while(!dst.empty()){
		num = dst.front();
		dst.pop_front();

		if(check(num, dq)){
			while(true){
				in = dq.front();
				dq.pop_front();
				if(num == in) break;
				else{
					cnt++;
					dq.push_back(in);
				}
			}
		} else {
			while(true){
				in = dq.back();
				dq.pop_back();
				if(num == in) {cnt++; break;}
				else{
					cnt++;
					dq.push_front(in);
				}
			}
		}
	}

	printf("%d\n", cnt);
	return 0;
}

bool check(int elem, std::deque<int> dq){
	int len = 0, dqLen = dq.size();
	auto end = dq.end();
	for(auto it = dq.begin(); it != end; it++){
		if(*it == elem) break;
		else len++;
	}
	if( 2*len <= dqLen+1 ) return true;
	else return false;
}