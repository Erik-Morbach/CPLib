// TODO: Verificar esse código
template<int maxp, int maxn>
struct dSparse{
	int n;
	int st[maxp][maxn];
	int nSiz;
	int nLog;
	int *v;

	dSparse(){
	}
	dSparse(int n, int *v){
		init(n,v);
	}
	void init(int n, int *v){
		this->v = v;
		this->n = n;
	}
	 
	void build(){
		nSiz = 1;
		nLog = 0;
		while(nSiz<n){
			nLog++;
			nSiz*=2;
		}
		for(int h=0;h<nLog;h++){
			int blockSiz = nLog - h;
			for(int block=0;block<(1<<h);block++){
				int ini = block<<blockSiz;
				int fin = (block+1)<<blockSiz;
				int mid = (ini+fin)/2;
				st[h][mid] = v[mid];
				st[h][mid-1] = v[mid-1];
				for(int i=mid+1;i<fin;i++) st[h][i] = min(st[h][i-1],v[i]);
				for(int i=mid-2;i>=ini;i--) st[h][i] = min(st[h][i+1], v[i]);
			}
	 
		}
	}
	 
	int query(int l, int r){
		if(l==r) return st[nLog-1][l];
		int lev = nLog - 32 + __builtin_clz(l^r);
		return min(st[lev][l], st[lev][r]);
	}
};
