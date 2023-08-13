const int maxn = 4123;

template<typename T, int N, int M, T v[N][M]>
struct Seg2D{
	int ix[N], iy[M];
	int fx[N], fy[M];
	T value[N][M];
	T iden;
	inline T fun(T a, T b){
		return a+b;
	}
	void build_x(int lx, int rx, int ly, int ry, int idx=1){
		ix[idx] = lx;
		fx[idx] = rx;
		if(lx!=rx){
			int m = (lx+rx)/2;
			build_x(lx, m, ly, ry, idx*2);
			build_x(m+1, rx, ly, ry, idx*2+1);
		}
		build_y(ly, ry, lx, rx, idx);
	}
	void build_y(int ly, int ry, int lx, int rx, int idx, int idy=1){
		iy[idy] = ly;
		fy[idy] = ry;
		if(ly == ry){
			if(lx == rx) value[idx][idy] = v[lx][ly];
			else value[idx][idy] = fun(value[idx*2][idy], value[idx*2+1][idy]);
		}
		else{
			int m = (ly+ry)/2;
			build_y(ly, m, lx, rx, idx, idy*2);
			build_y(m+1,ry, lx, rx, idx, idy*2+1);
			value[idx][idy] = fun(value[idx][idy*2], value[idx][idy*2+1]);
		}
	}

	T queryY(int qly, int qry, int idx=1, int idy=1){
		if(iy[idy] > qry || fy[idy] < qly) return iden;
		if(qly <= iy[idy] && fy[idy] <= qry) return value[idx][idy];
		T response = queryY(qly, qry, idx, idy*2);
		response = fun(response, queryY(qly, qry, idx, idy*2+1));
		return response;
	}

	T queryX(int qlx, int qly, int qrx, int qry, int idx=1, int idy=1){
		if(ix[idx] > qrx || fx[idx] < qlx) return iden;
		if(qlx <= ix[idx] && fx[idx] <= qrx) return queryY(qly, qry, idx, idy);
		T response = queryX(qlx, qly, qrx, qry, idx*2, idy);
		response = fun(response, queryX(qlx, qly, qrx, qry, idx*2+1, idy));
		return response;
	}

	T updateY(int qiy, T value, int idx=1, int idy=1){
		if(qiy < iy[idy] || fy[idy] < qiy) return this->value[idx][idy];
		T response = updateY(qiy, value, idx, idy*2);
		response = fun(response, updateY(qiy, value, idx, idy*2+1));
		return this->value[idx][idy] = response;
	}

	T updateX(int qix, int qiy, T value, int idx=1, int idy=1){
		if(qix < ix[idx] || fx[idx] < qix) return this->value[idx][idy];
		if(ix[idx]==fx[idx] && ix[idx]==qix) return updateY(qiy, value, idx, idy);
		T response = queryX(qix, qiy, value, idx*2, idy);
		response = fun(response, queryX(qix, qiy, value, idx*2+1, idy));
		return response;
	}

};

int v[maxn][maxn];
Seg2D<int, maxn, maxn, v> seg; // usage
