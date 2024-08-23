const int maxn = 1123;
const int maxm = 51234;

struct Edge{
	int from, to;
	ll cap;
	ll cost;
}edges[maxm];
int cnt = 0;

vi prox[maxn];

ll dist[maxn];
ll which[maxn];

void resetState(int n){
	for(int i=0;i<=n;i++) prox[i].clear();
	cnt = 0;
}

void dijkstra(int s, int t){
	fill(dist, dist+maxn, LINF);
	priority_queue<pair<ll,int>, vector<pair<ll, int>>, less<pair<ll,int>>> que;

	dist[s] = 0;
	que.push({0,s});

	while(!que.empty()){
		auto atu = que.top();
		que.pop();
		for(int edNum: prox[atu.y]){
			int to = edges[edNum].to;
			if(edges[edNum].cap<=0) continue;
			ll newDist = atu.x + edges[edNum].cost;
			if(dist[to] <= newDist) continue;
			dist[to] = newDist;
			which[to] = edNum;
			que.push({dist[to], to});
		}
	}
}
ll flow(int s, int t, ll K){
	ll flow = 0;
	ll cost = 0;
	while(flow < K){
		dijkstra(s, t);
		if(dist[t]>=LINF) break;
		ll f = K - flow;
		int curr = t;
		while(curr != s){
			int edNum = which[curr];
			f = min(f, edges[edNum].cap);
			curr = edges[edNum].from;
		}

		flow += f;
		cost += f*dist[t];

		curr = t;
		while(curr != s){
			int edNum = which[curr];
			edges[edNum].cap -= f;
			edges[edNum^1].cap += f;
			curr = edges[edNum].from;
		}
	}
	if(flow < K) return -1;
	return cost;
}
void _addEdg(int idx, int from, int to, ll cost, ll cap){
	edges[idx].from = from;
	edges[idx].to = to;
	edges[idx].cost = cost;
	edges[idx].cap = cap;
}
void add(int a, int b, ll c, ll cap){
	prox[a].push_back(cnt);
	_addEdg(cnt, a, b, c, cap);
	cnt++;
	prox[b].push_back(cnt);
	_addEdg(cnt, b, a, -c, 0);
	cnt++;
	// Bidirecional, então adiciona mais essas duas
	prox[b].push_back(cnt);
	_addEdg(cnt, b, a, c, cap);
	cnt++;
	prox[a].push_back(cnt);
	_addEdg(cnt, a, b, -c, 0);
	cnt++;
}

