int memo[112][112];
int dp(int idV, int idW, const vi &v, const vi &w){
	int &ans = memo[idV][idW];
	if(ans != -1) return ans;
	ans = INF;
	if(idV < v.size())
		ans = min(ans, dp(idV+1, idW, v, w)+1);
	if(idW < w.size())
		ans = min(ans, dp(idV, idW+1, v, w)+1);
	if(idV < v.size() && idW < w.size() && v[idV] == w[idW])
		ans = min(ans, dp(idV+1, idW+1, v, w));
	if(idV == v.size() && idW == w.size()) ans = 0;
	return ans;
}
