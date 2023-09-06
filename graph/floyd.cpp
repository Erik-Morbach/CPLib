const int maxn = 100;
int n;
int dist[maxn][maxn];
int matr[maxn][maxn];
void floyd(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			matr[i][j] = dist[i][j];
			if(dist[i][j] == -1) matr[i][j] = INF;
		}
	}

	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				matr[i][j] = min(matr[i][j], matr[i][k]+matr[k][j]);
			}
		}
	}
}

