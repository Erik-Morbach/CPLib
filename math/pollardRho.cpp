ll binPow(ll base, ll ex, ll mod){
	if(ex==0) return 1;
	if(ex==1) return base;
	ll ans = binPow(base, ex/2, mod);
	ans = (ans*ans)%mod;
	if(ex%2) ans = (ans*base)%mod;
	return ans;
}

bool isPrime(ll p){
	if(p < 4) return p==2 || p == 3;
	int it = 10;
	while(it--){
		ll a = ((rand())%(p-3)) + 2;
		if(binPow(a,p-1, p) != 1) return false;
	}
	return true;
}

ll f(ll x, ll c, ll mod){
	return ((((x*x)%mod + x)%mod + c)%mod)%mod;
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

