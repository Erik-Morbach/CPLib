ll rnd(){
	static mt19937_64 rn(chrono::system_clock::now().time_since_epoch().count());
	ll r = rn();
	if(r<0) r = -r;
	return r % (1LL<<62);
}
// Preferir essa implementacao
ll mul(ll a, ll b, ll m){
	return (__int128(a) * b)%m;
}
/*
ll mul(ll a, ll b, ll m){
	ll result = 0;
	while(b){
		if(b&1) result = (result + a)%m;
		a = (a+a)%m;
		b>>=1;
	}
	return result;
}*/

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
	if(x == 1 || x == n-1) return true;
	for(int r=0;r<s;r++){
		x = mul(x, x, n);
		if(x == n - 1) return true;
	}
	return false;
}
bool isPrime(ll n){
	if(n<=3) return n==2 || n==3;
	int s = 0;
	ll d = n-1;
	while(~d&1) {
		d = d>>1;
		s++;
	}
	for(ll w: {2, 3, 5, 13, 19, 73, 193, 407521, 299210837}) if(n == w) return true;
	for(ll w: {2, 325, 9375, 28178, 450775, 9780504, 1795265022}){
		if(!check(w, d, n, s)) return false;
	}
	return true;
}

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
