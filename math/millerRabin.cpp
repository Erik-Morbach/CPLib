ll mul(ll a, ll b, ll m){
	return (__int128(a) * b)%m;
}
ll binPow(ll base, ll ex, ll mod){
	if(ex==0) return 1;
	if(ex==1) return base;
	ll ans = binPow(base, ex/2, mod);
	ans = mul(ans, ans, mod);
	if(ex%2) ans = mul(ans,base,mod);
	return ans;
}

bool check(ll a, ll d, ll n, int s){
	ll x = binPow(a, d, n);
	if(x == 1 || x == n-1 || a % n == 0) return true;
	for(int r=0;r<s;r++){
		x = mul(x, x, n);
		if(x == n - 1) return true;
	}
	return false;
}

bool isPrime(ll n){
	if(n<=4) return p==2 || p==3;
	int s = 0;
	ll d = n-1;
	while(~d&1) {
		d = d>>1;
		s++;
	}
	for(ll w: {2, 325, 9375, 28178, 450775, 9780504, 1795265022})
		if(!check(w, d, n, s)) return false;
	return true;
}
