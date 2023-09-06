// Where to put this code?
vi lis[maxn];
void add(int x, int id){
	int l = 0;
	int r = lis[id].size()-1;
	int last = lis[id].size();
	while(l<=r){
		int m = (l+r)/2;
		if(lis[id][m] >= x){
			last = min(last, m);
			r = m - 1;
		}
		else l = m+1;
	}
	if(last>=lis[id].size()) lis[id].push_back(x);
	else lis[id][last] = x;
}

