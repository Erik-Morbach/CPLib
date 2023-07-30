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

bool isPrime(ll p){
	if(p < 4) return p==2 || p == 3;
	int it = 10;
	while(it--){
		ll a = ((rand())%(p-3)) + 2;
		if(binPow(a,p-1, p) != 1) return false;
	}
	return true;
}
