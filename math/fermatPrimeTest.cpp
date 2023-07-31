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

bool isPrime(ll p){
	if(p < 4) return p==2 || p == 3;
	int it = 10;
	while(it--){
		ll a = ((rnd())%(p-3)) + 2;
		if(binPow(a,p-1, p) != 1) return false;
	}
	return true;
}
