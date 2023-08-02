template<typename T>
struct SegTree{
	static const int len = 2*maxn;
	T v[len];
	int n;

	void build(){
		for(int i=n-1;i>=0;i--){
			v[i]= min(v[i*2], v[i*2+1]);
		}
	}
 
	int query(int l, int r){
		r++;
		l+=n;r+=n;
		int ans = INF;
		for(;l<r;l/=2,r/=2){
			if(l&1) ans = min(ans,v[l++]);
			if(r&1) ans = min(ans,v[--r]);
		}
		return ans;
	}
 
	void update(int i, int val){
		i+=n;
		v[i].value = val;
		i/=2;
		while(i>0){
			v[i] = min(v[2*i], v[2*i+1]);
			i/=2;
		}
	}
};

