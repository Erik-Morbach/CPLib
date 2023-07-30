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

ll f(ll x, ll c, ll mod){
	return (mul(x,x,mod) + c)%mod;
}

ll rho(ll n){
	if(isPrime(n)) return n;
	ll x0 = (rand()%(n-1)) + 1;
	ll c = (rand()%(n-1))+1;
	ll turt = f(x0, c, n);
	ll rabit = f(turt, c, n);
	while(1){
		ll diff = abs(turt-rabit);
		ll g = __gcd(diff, n);

		turt = f(turt, c, n);
		rabit = f(rabit, c, n);
		rabit = f(rabit, c, n);
		if(g==n) return rho(n);
		if(g==1) continue;
		return g;
	}
	return n;
}

