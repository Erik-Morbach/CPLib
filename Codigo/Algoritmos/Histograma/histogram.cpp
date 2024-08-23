ll ans = 0;
vll esq(m+2);
vll dir(m+2);

S[0] = -1; // 1 -> m
S[m+1] = -1;
vector<ll> sta;
sta.pb(0);
for(int j=1;j<=m;j++){
	while(S[sta.back()] >= S[j])
		sta.pop_back();
	esq[j] = sta.back();
	sta.pb(j);
}
sta.clear();
sta.pb(m+1);
for(int j=m;j>=1;j--){
	while(S[sta.back()] >= S[j])
		sta.pop_back();
	dir[j] = sta.back();
	sta.pb(j);
}
for(int j=1;j<=m;j++){ // Maybe only one side is enough
	ans = max(ans, (dir[j] - esq[j]) * S[j]);
}
