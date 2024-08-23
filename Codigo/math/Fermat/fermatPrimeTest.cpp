// Precisa dos métodos:
//    utils::{mul, rand, binPow}

bool isPrime(ll p){
	if(p < 4) return p==2 || p == 3;
	int it = 10;
	while(it--){
		ll a = ((rnd())%(p-3)) + 2;
		if(binPow(a,p-1, p) != 1) return false;
	}
	return true;
}
