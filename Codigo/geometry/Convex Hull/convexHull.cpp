bool ccw(ii a, ii b, ii c, bool colinear=false){
	ii x = {b.x - a.x, b.y - a.y};
	ii y = {c.x - b.x, c.y - b.y};
	int val = x.x * y.y - x.y * y.x;
	return val > 0 || (colinear && val==0);
}

vi convexHul(const vii &points){
	int n = points.size();
	vi p(n);
	for(int i=0;i<n;i++) p[i] = i;
	sort(all(p), [&](int a, int b){ return points[a] < points[b]; });

	vi h(2*n);
	int k = 0;

	for(int i=0;i<n;i++){
		while(k>=2 && !ccw(points[h[k-2]], points[h[k-1]], points[p[i]], true)) k--;
		h[k++] = p[i];
	}
	for(int i=n-1,t=0;i>=0;--i){
		while(t>=2 && !ccw(points[h[k-2]], points[h[k-1]], points[p[i]], true)) {
			k--;
			t--;
		}
		h[k++] = p[i];
		t++;
	}
	h.resize(k);
	sort(all(h));
	return h;
}

