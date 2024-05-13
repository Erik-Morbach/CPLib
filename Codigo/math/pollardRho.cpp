// Precisa dos métodos:
//    millerRabin::isPrime
//    utils::{mul, rand}

ll f(ll x, ll c, ll mod){
	return (mul(x,x,mod) + c)%mod;
}

ll rho(ll n) {
	if(isPrime(n)) return n;
	for(int w: {2,3,5,7,11,13,17,19})
		if(n%w==0) return w;
	ll x0 = (rnd()%(n-2)) + 2;
	ll c = (rnd()%(n-1)) + 1;
	ll x = x0;
	ll y = x0;
	ll g = 1;
	while (g == 1) {
		x = f(x, c, n);
		y = f(y, c, n);
		y = f(y, c, n);
		g = __gcd(abs(x - y), n);
		if(g == n) return rho(n);
	}
	return g;
}
