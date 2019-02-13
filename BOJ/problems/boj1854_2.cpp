/*
 *    I quoted koosaga's code. (4470606)
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

vector<pi> gph[1005];
priority_queue<int> dis[1005];
int n, m, k;

int main(){
	cin >> n >> m >> k;
	for(int i=0; i<m; i++){
		int s, e, x;
		scanf("%d %d %d",&s,&e,&x);
		gph[s].push_back(pi(x, e));
	}
	priority_queue<pi, vector<pi>, greater<pi> > pq;
	dis[1].push(0);
	pq.push(pi(0, 1));
	while(!pq.empty()){
		auto x = pq.top();
		pq.pop();
		if(dis[x.second].top() < x.first) continue;
		for(auto &i : gph[x.second]){
			pi w(i.first + x.first, i.second);
			if(dis[i.second].size() < k || dis[i.second].top() > w.first){
				dis[i.second].push(w.first);
				pq.push(w);
				if(dis[i.second].size() > k) dis[i.second].pop();
			}
		}
	}
	for(int i=1; i<=n; i++){
		if(dis[i].size() < k) puts("-1");
		else printf("%d\n", dis[i].top());
	}
}


