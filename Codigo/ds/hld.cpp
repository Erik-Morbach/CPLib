struct HLD{
	int cnt = 0;
	vector<int> prox[maxn];
	int pai[maxn];
	int siz[maxn];
	int pos[maxn];
	int h[maxn];

	void addEdge(int u, int v){
		prox[u].push_back(v);
		prox[v].push_back(u);
	}

	void build(int root){
		dfs(root);
		cnt = 0;
		buildHld(root);
		seg.build(0, cnt-1);
	}

	void dfs(int v, int p=-1){
		pai[v] = p;
		siz[v] = 1;
		for(int &w: prox[v]){
			if(w==p) continue;
			dfs(w,v);
			siz[v] += siz[w];
			if(siz[w] > siz[prox[v][0]] or prox[v][0]==p)
				swap(w, prox[v][0]);
		}
	}
	void buildHld(int v, int p=-1){
		pos[v] = cnt++;
		for(int &w: prox[v]){
			if(w == p) continue;
			h[w] = (w==prox[v][0]?h[v]:w);
			buildHld(w, v);
		}
	}

	ll query(int a, int b){
		//cout << "on query "<<a <<", "<<b <<endl;
		if(pos[a] > pos[b]) swap(a,b);
		if(h[a] == h[b]) 
			return seg.query(pos[a], pos[b]);
		return seg.query(pos[h[b]], pos[b]) + query(a, pai[h[b]]);
	}
	void update(int a, int b, ll x){
		//cout << "on update "<<a <<", "<<b <<", "<<x<<endl;
		if(pos[a] > pos[b]) swap(a,b);
		if(h[a] == h[b]){
			seg.update(pos[a], pos[b], x);
			return;
		}
		seg.update(pos[h[b]], pos[b], x);
		update(a, pai[h[b]], x);
	}
}hld;

