// Precisa dos métodos:
//    utils::{mul, rand, binPow}
//    millerRabin::isPrime

ll f(ll x, ll c, ll mod){
	return (mul(x,x,mod) + c)%mod;
}

ll brent(ll n){
	if(isPrime(n)) return n;
	for(int w: {2,3,5,7,11,13,17,19})
		if(n%w==0) return w;
	ll x0 = (rnd()%(n-1)) + 1;
	ll c = (rnd()%(n-1))+1;
	ll turt = x0;
	ll rabit = f(turt, c, n);
	ll g = 1;

	ll lastRabit = rabit;
	int l = 1;
	int m = 128;
	while(g==1){
		turt = rabit;
		for(int i=0;i<l;i++)
			rabit = f(rabit, c, n);

		ll q = 1;
		for(int k=0;k<l;k+=m){
			lastRabit = rabit;
			int lim = min(m, l-k);
			for(int i=0;i<lim; i++){
				rabit = f(rabit, c, n);
				q = mul(q, abs(rabit - turt), n);
			}
			g = __gcd(q, n);
			if(g!=1) break;
		}
		l *= 2;
	}
	if(g == n){
		g = 1;
		while(g == 1){
			lastRabit = f(lastRabit, c, n);
			g = __gcd(abs(lastRabit - turt), n);
		}
	}
	return g;
}
