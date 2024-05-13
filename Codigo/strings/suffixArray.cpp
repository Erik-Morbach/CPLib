vi makeSa(const string &s){
	int n = s.size();
	int N = max(n,300);
	vi sa(n), ra(n);
	for(int i=0;i<n;i++){
		sa[i] = i;
		ra[i] = s[i];
	}
	vi cnt(N,0);
	vi nsa(sa), nra(n);
	for(int k=0;k<n;k=(k?k*2:k+1)){
		fill(all(cnt), 0);
		for(int i=0;i<n;i++){
			nsa[i] = (sa[i] - k + n)%n;
			cnt[ra[i]]++;
		}
		for(int i=1;i<N;i++) cnt[i] += cnt[i-1];
		for(int i=n-1;i>=0;i--) sa[--cnt[ra[nsa[i]]]] = nsa[i];
 
		int r = 0;
		nra[sa[0]] = r;
		for(int i=1;i<n;i++){
			nra[sa[i]] = r += ra[sa[i]] != ra[sa[i-1]] or ra[(sa[i]+k)%n] != ra[(sa[i-1]+k)%n];
		}
		swap(nra, ra);
		if(ra[sa[n-1]]==n-1) break;
	}
	return sa;
}

vi kasai(const string &s, const vi &sa){
	int n = s.size();
	vi lcp(n,0), ra(n);
	for(int i = 0;i<n;i++) ra[sa[i]] = i;
	int k = 0;
	for(int i=0;i<n;i++, k -= !!k){
		if(ra[i]==n-1){
			k = 0;
			continue;
		}
		int j = sa[ra[i]+1];
		while(i+k < n  and j+k < n  and s[i+k]==s[j+k]) k++;
		lcp[ra[i]] = k;
	}
	return lcp;
}


