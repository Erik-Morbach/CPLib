// Precisa dos métodos:
//    utils::{mul, binPow}

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
